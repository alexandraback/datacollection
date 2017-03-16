#include<cstdio>
#include<cstring>
#include<algorithm>
char s[10][10];
bool checkWin(char x) {
    for (int i=0;i<4;i++) {
        bool checked=true;
        for(int j=0;j<4;j++) {
            if (s[i][j]!=x && s[i][j]!='T') {
                checked=false;
            }
        }
        if (checked) return true;
        checked=true;
        for (int j=0;j<4;j++) {
            if (s[j][i]!=x && s[j][i]!='T') {
                checked=false;
            }
        }
        if (checked) return true;
    }
    bool checked=true;
    for (int i=0;i<4;i++){
        if (s[i][i]!=x && s[i][i]!='T') {
            checked=false;
        }
    }
    if (checked) return true;
    checked=true;
    for (int i=0;i<4;i++) {
        if (s[i][3-i]!=x && s[i][3-i]!='T') {
            checked=false;
        }
    }
    return checked;
}
int main() {
    int T;
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        for(int i=0;i<4;i++) {
            scanf("%s", s[i]);
        }
        
        bool notEnd = false;
        for (int i=0;i<4;i++) {
            for (int j=0;j<4;j++) {
                if (s[i][j]=='.') {
                    notEnd = true;
                }
            }
        }
        bool xWin = checkWin('X');
        bool oWin = checkWin('O');
        printf("Case #%d: ", t);
        if (xWin) {
            printf("X won\n");
        } else if (oWin) {
            printf("O won\n");
        } else if(notEnd) {
            printf("Game has not completed\n");
        } else {
            printf("Draw\n");
        }
    }
}
