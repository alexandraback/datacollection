#include <cstdio>
#include <iostream>

using namespace std;

bool sip, empate;
char A[10][10], Z[20];
int casos;

bool checa(int x, int y, int sx, int sy, char que){
    sip=true;
    for(int i=1; i<=4; i++){
        if(A[x][y]!=que and A[x][y]!='T'){
            sip=false;
            break;
        }
        x+=sx;
        y+=sy;
    }
    return sip;
}

bool gano(char que){
    if(checa(1, 4, 1, -1, que))
        return true;
    if(checa(4, 4, -1, -1, que))
        return true;
    if(checa(1, 1, 0, 1, que))
        return true;
    if(checa(2, 1, 0, 1, que))
        return true;
    if(checa(3, 1, 0, 1, que))
        return true;
    if(checa(4, 1, 0, 1, que))
        return true;
    if(checa(1, 1, 1, 0, que))
        return true;
    if(checa(1, 2, 1, 0, que))
        return true;
    if(checa(1, 3, 1, 0, que))
        return true;
    if(checa(1, 4, 1, 0, que))
        return true;
    return false;
}

int main()
{
    freopen("ticin.txt","r",stdin);
	freopen("tic.txt","w",stdout);
    scanf("%d",&casos);
    for(int va=1; va<=casos; va++){
        empate=true;
        for(int i=4; i>0; i--){
            scanf("%s",Z);
            for(int e=0; e<4; e++){
                A[e+1][i]=Z[e];
                if(Z[e]=='.'){
                    empate=false;
                }
            }
        }
        if(gano('X')){
            printf("Case #%d: X won\n",va);
        }
        else if(gano('O')){
            printf("Case #%d: O won\n",va);
        }
        else if(empate){
            printf("Case #%d: Draw\n",va);
        }
        else {
            printf("Case #%d: Game has not completed\n",va);
        }
    }
    return 0;
}
