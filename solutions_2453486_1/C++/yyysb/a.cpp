#include <cstdio>
#include <cstring>

using namespace std;

int T,fg;
char a[5][5];

bool check(char c){
    for(int i=0; i<4; ++i){
        int tmp=1;
        for(int j=0; j<4; ++j)
            if(a[i][j]!=c && a[i][j]!='T') tmp=0;
        if (tmp) return true;
        tmp=1;
        for(int j=0; j<4; ++j)
            if(a[j][i]!=c && a[j][i]!='T') tmp=0;
        if (tmp) return true;
    }
    int tmp=1;
    for(int j=0; j<4; ++j)
        if(a[j][j]!=c && a[j][j]!='T') tmp=0;
    if (tmp) return true;
    tmp=1;
    for(int j=0; j<4; ++j)
        if(a[3-j][j]!=c && a[3-j][j]!='T') tmp=0;
    if (tmp) return true;
    return false;
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d", &T);
    for(int cs=1;cs<=T;++cs){
        fg = 0;
        for(int i=0;i<4; ++i){
            scanf("%s",a[i]);
            for(int j=0; j<4;++j)
                if(a[i][j]=='.') fg = 1;
        }
        printf("Case #%d: ",cs);
        if(check('X'))
            puts("X won");
        else if(check('O'))
            puts("O won");
        else if (fg)
            puts("Game has not completed");
        else puts("Draw");
    }
}
