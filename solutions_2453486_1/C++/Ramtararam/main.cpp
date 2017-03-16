#include <iostream>
#include <stdio.h>

using namespace std;

char game[4][4];

int main()
{
    int n;

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    scanf("%d", &n);

    for(int h=0; h<n; ++h){
        printf("Case #%d: ", h+1);

        for(int i=0;i<4;++i){
            scanf("%s", game[i]);
        }

        bool won=false;
        for(int i=0;i<4;++i){
            int t=0,x=0,o=0;
            for(int j=0;j<4;++j){
                if(game[i][j] == 'O')
                    o += 1;
                else if(game[i][j] == 'X')
                    x += 1;
                else if(game[i][j] == 'T')
                    t += 1;
            }
            if(x == 3 && t == 1 || x == 4){
                printf("X won\n");
                won=true;
                break;
            }
            if(o == 3 && t == 1 || o == 4){
                printf("O won\n");
                won=true;
                break;
            }
        }

        if(won) continue;

        for(int i=0;i<4;++i){
            int t=0,x=0,o=0;
            for(int j=0;j<4;++j){
                if(game[j][i] == 'O')
                    o += 1;
                else if(game[j][i] == 'X')
                    x += 1;
                else if(game[j][i] == 'T')
                    t += 1;
            }
            if(x == 3 && t == 1 || x == 4){
                printf("X won\n");
                won=true;
                break;
            }
            if(o == 3 && t == 1 || o == 4){
                printf("O won\n");
                won=true;
                break;
            }
        }

        if(won) continue;

        for(int i=0;i<1;++i){
            int t=0,x=0,o=0;
            for(int j=0;j<4;++j){
                if(game[j][j] == 'O')
                    o += 1;
                else if(game[j][j] == 'X')
                    x += 1;
                else if(game[j][j] == 'T')
                    t += 1;
            }
            if(x == 3 && t == 1 || x == 4){
                printf("X won\n");
                won=true;
                break;
            }
            if(o == 3 && t == 1 || o == 4){
                printf("O won\n");
                won=true;
                break;
            }
        }

        if(won) continue;

        for(int i=0;i<1;++i){
            int t=0,x=0,o=0;
            for(int j=0;j<4;++j){
                if(game[j][3-j] == 'O')
                    o += 1;
                else if(game[j][3-j] == 'X')
                    x += 1;
                else if(game[j][3-j] == 'T')
                    t += 1;
            }
            if(x == 3 && t == 1 || x == 4){
                printf("X won\n");
                won=true;
                break;
            }
            if(o == 3 && t == 1 || o == 4){
                printf("O won\n");
                won=true;
                break;
            }
        }

        if(won) continue;

        bool dot = false;
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                if(game[i][j] == '.'){
                    dot = true;
                    break;
                }
            }
            if(dot) break;
        }

        if(dot){
            printf("Game has not completed\n");
        }else{
            printf("Draw\n");
        }

    }
    return 0;
}

