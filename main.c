#include <stdio.h>

//--------Global Variables--------\\
//players
char P1 = 'X';
char P2 = 'O';
int game_on = 1;//true
char empty_player = '-';

// gameboard
char board[3][3] = {{'-', '-', '-'},
                    {'-', '-', '-'},
                    {'-', '-', '-'}
                   };

//for game logic
int count = 0;

//functions
void draw_screen();
char change_player();
void place_player();
void input_pos();
void check_tie();
void check_column(int a);
void check_row(int a);
void check_diagonal();

//main
int main()
{
    //GAMELOOP
    while(game_on){
    draw_screen();
    input_pos();
    check_tie();
    for(int i=0;i<3;i++){
        check_column(i);
        check_row(i);
    }
    check_diagonal();
    }
    check_diagonal();
    return 0;
}

void draw_screen(){

    for(int i=0;i<3;i++){
        printf("\n\t\t");
        for(int j=0;j<3;j++){
            printf("%c ", board[i][j]);
            if (j==2){
                printf("\n");
            }

        }
    }
}

char change_player(){
    if(count%2 == 0){
        count++;
        return P1;

    }
    else{
        count++;
        return P2;
    }
}

void input_pos(){
    char player;
    int pos;

    printf("Enter Player pos:");
    scanf("%d", &pos);
    pos--;
    place_player(pos);
}

void place_player(int pos){
    int x, y;
    char player;
    player = change_player();
    x = pos/3;
    y = pos%3;

    if(board[x][y] == empty_player){
        board[x][y] = player;
    }
    else{
        printf("Illegal Move!");
    }
}

void check_tie(){
    int x=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (board[i][j] != empty_player){
                x++;
            }
        }
    }
    if(x==9){
        printf("game tied!");
        draw_screen();
        game_on = 0;
    }

}

void check_column(int a){
    int x = 0;
    int o = 0;
   for(int i=0;i<3;i++){-
        if(board[a][i] == P1){
            x++;
        }
        else if(board[a][i] == P2){
            o++;
        }
   }
   check_win(P1, x);
   check_win(P2, o);
}

void check_row(int a){
    int x=0, o=0;
    for(int i=0;i<3;i++){
        if(board[i][a] == P1){
            x++;
        }
        else if(board[i][a] == P2){
            o++;
        }
        check_win(P1, x);
        check_win(P2, o);
   }
}

void check_win(char player, int a){
    if(a==3){
    printf("%c Won!", player);
    game_on = 0;//end gameloop
    }
}

void check_diagonal(){

    char d1[3] = {board[0][0], board[1][1],
                    board[2][2]} ;
    char d2[3] = {board[0][2], board[1][1],
                    board[2][0]} ;

    int x1 = 0, x2 = 0, o1 = 0, o2 = 0;

    for(int i=0;i<3;i++){
        if(d1[i] == P1){
            x1++;
        }
        else if(d1[i] == P2){
            o1++;
        }
        if(d2[i] == P1){
            x2++;
        }
        else if(d2[i] == P2){
            o2++;
        }
    }
    check_win(P1, x1);
    check_win(P1, x2);
    check_win(P2, o1);
    check_win(P2, o2);
}
