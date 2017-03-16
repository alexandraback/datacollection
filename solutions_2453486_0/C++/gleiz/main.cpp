#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char board[8][8] = {{0}};

const int XWON = 0;
const int OWON = 1;
const int DRAW = 2;
const int NCOM = 3;

int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

int checkboard(){
    int xwon = 0;
    int owon = 0;
    int empt = 0;

    for (int i = 0; i<4; i++){
        for (int j = 0; j<4; j++){
            if (board[i][j] == '.'){
                empt++;
            }
            for (int d = 0; d < 8; d++){
                int xacc = 0, oacc = 0, current_x = i, current_y = j;
                for (int step = 0; step<4; step++){
                    if (current_x >= 0 && current_x < 4 &&
                        current_y >= 0 && current_y < 4){
                        if (board[current_x][current_y] == 'X'){
                            xacc++;
                        }else if (board[current_x][current_y] == 'O'){
                            oacc++;
                        }else if (board[current_x][current_y] == 'T'){
                            xacc++;
                            oacc++;
                        }else{
                            xacc = oacc = 0;
                        }
                    }else{
                        break;
                    }

                    if (xacc >= 4){
                        xwon = 1;
                    }
                    if (oacc >= 4){
                        owon = 1;
                    }

                    current_x += dir[d][0];
                    current_y += dir[d][1];
                } // for step
            } // fpr dir
        } // for j
    } // for i

    if (xwon == 1 && owon == 1){
        return DRAW;
    }else if (xwon == 1){
        return XWON;
    }else if (owon == 1){
        return OWON;
    }else if (xwon == 0 && owon == 0){
        if (empt == 0){
            return DRAW;
        }else{
            return NCOM;
        }
    }
}
int main()
{
    int T = 0;
    scanf("%d", &T);

    for (int cas = 1; cas<=T; cas++){
        memset(board, 0, sizeof(board));
        for (int i = 0; i<4; i++){
            scanf("%s", board[i]);
        }
        int stat = checkboard();
        printf("Case #%d: ", cas);
        switch (stat){
            case XWON:
                printf("X won\n");
                break;
            case OWON:
                printf("O won\n");
                break;
            case DRAW:
                printf("Draw\n");
                break;
            default:
                printf("Game has not completed\n");
                break;
        }

    }
    return 0;
}
