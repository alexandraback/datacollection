#include <cstdio>
#include <cstring>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int cnt[9];
char board[5][6];
char *str = (char*)"OXT.";

int check(){
    if(cnt[0] + cnt[2] == 4){ puts("O won"); return 1;}
    if(cnt[1] + cnt[2] == 4){ puts("X won"); return 1;}
    memset(cnt,0,sizeof(cnt));
    return 0;
}

void judge(){
    memset(cnt,0,sizeof(cnt));

    rep(i,4){
        rep(j,4) cnt[strchr(str,board[i][j]) - str]++;
        if(check()) return;

        rep(j,4) cnt[strchr(str,board[j][i]) - str]++;
        if(check()) return;
    }

    rep(i,4) cnt[strchr(str,board[i][i]) - str]++;
    if(check()) return;

    rep(i,4) cnt[strchr(str,board[i][3-i]) - str]++;
    if(check()) return;

    rep(i,4) rep(j,4) cnt[strchr(str,board[i][j]) - str]++;

    if(cnt[3] == 0){ puts("Draw"); return;}
    puts("Game has not completed"); return;
}

int main(){
    int T;
    scanf("%d\n",&T);

    rep(C,T){
        rep(i,5) fgets(board[i],6,stdin);
        printf("Case #%d: ",C+1);
        judge();
    }
}
