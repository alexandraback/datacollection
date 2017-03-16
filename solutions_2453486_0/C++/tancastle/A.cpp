#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int a[5][5];
char tmp[10];

bool judge(int t) {
    int flag;
    for(int i=1; i<=4; i++) {
        flag = 1;
        for(int j=1; j<=4; j++) {
            if(!(a[i][j] == t || a[i][j] == 9)) flag = 0;
        }
        if(flag) return 1;
    }
    for(int i=1; i<=4; i++) {
        flag = 1;
        for(int j=1; j<=4; j++) {
            if(!(a[j][i] == t || a[j][i] == 9)) flag = 0;
        }
        if(flag) return 1;
    }
    flag = 1;
    for(int i=1; i<=4; i++) {
        if(!(a[i][i] == t || a[i][i] == 9)) flag = 0;
    }
    if(flag) return 1;
    flag = 1;
    for(int i=1; i<=4; i++) {
        if(!(a[i][5-i] == t || a[i][5-i] == 9)) flag = 0;
    }
    if(flag) return 1;
    return 0;
}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++) {
        int flag = 1;
        for(int i=1; i<=4; i++) {
            scanf("%s", tmp);
            for(int j=1; j<=4; j++) {
                if(tmp[j-1] == '.') flag = 0;
                switch(tmp[j-1]) {
                    case '.': a[i][j] = 0;break;
                    case 'X': a[i][j] = 1;break;
                    case 'O': a[i][j] = 2;break;
                    case 'T': a[i][j] = 9;break;
                    default: a[i][j] = 8;break;
                }
            }
        }

        /*
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
        */

        printf("Case #%d: ", kase);

        bool xx, oo;
        xx = judge(1); oo = judge(2);
        if(xx || oo) {
            if(xx) printf("X won\n");
            else printf("O won\n");
        }
        else {
            if(!flag) printf("Game has not completed\n");
            else printf("Draw\n");
        }
    }
    return 0;
}
