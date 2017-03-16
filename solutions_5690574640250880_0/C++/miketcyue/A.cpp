#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int R,C,M;
char g[1010][1010];
void work1()
{
    if (R == 1) {
        for (int j = 0; j < M; j++) g[0][j] = '.';
    }
    else
    if (C == 1) {
        for (int i = 0; i < M; i++) g[i][0] = '.';
    }
    g[0][0] = 'c';

    for (int i = 0 ; i< R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c",g[i][j]);
        }
        printf("\n");
    }
}
void work2()
{
    if (M == 1) {
        g[0][0] = 'c';
        for (int i = 0 ; i< R; i++) {
            for (int j = 0; j < C; j++) {
                printf("%c",g[i][j]);
            }
            printf("\n");
        }
        return;
    }
    if (M % 2 == 1 || M == 2) {printf("Impossible\n");return;}
    if (R == 2) {
        for (int j = 0; j < C; j++) {
            if (M >= 2) {
                M -= 2;
                g[0][j] = g[1][j] = '.';
            }
            else
            if (M == 1) {
                M--;
                g[0][j] = '.';
            }
        }
    }
    else {
        for (int i = 0; i < R; i++) {
            if (M >= 2) {
                M -= 2;
                g[i][0] = g[i][1] = '.';
            }
            else
            if (M == 1) {
                M--;
                g[i][0] = '.';
            }
        }
    }
    g[0][0] = 'c';

    for (int i = 0 ; i< R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c",g[i][j]);
        }
        printf("\n");
    }

}
void work3()
{
    if (M == 1) {
        g[0][0] ='c';
        for (int i = 0 ; i< R; i++) {
            for (int j = 0; j < C; j++) {
                printf("%c",g[i][j]);
            }
            printf("\n");
        }
        return ;
    }
    if (M == 2 || M == 3 || M == 5 || M == 7) {printf("Impossible\n");return;}
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) g[i][j] = '.';
    M -= 4;
    if (M > 0) {
        M -= 2;
        g[2][0] = g[2][1] = '.';
    }
    if (M > 0) {
        M -= 2;
        g[0][2] = g[1][2] = '.';
    }
    for (int j = 2; j < C; j++) {
        if (M >= 2) {
            M -= 2;
            g[0][j] = g[1][j] = '.';
        }
    }
    for (int i = 2; i < R; i++) {
        if (M >= 2) {
            M -= 2;
            g[i][0] = g[i][1] = '.';
        }
    }
    if (M == 1) {
        M--;
        g[2][2] = '.';
    }
    for (int i = 0; i < R ;i++)
        for (int j = 0; j < C; j++)
        if (g[i][j] == '*' && M > 0) {
            M--;
            g[i][j] = '.';
        }
    g[0][0] = 'c';
    for (int i = 0 ; i< R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c",g[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int cas = 1;
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&R,&C,&M);
        M = R * C - M;
        int cnt = 0;
        for (int i = 0 ; i< R; i++)
            for (int j = 0; j < C; j++) g[i][j] ='*';
        printf("Case #%d:\n",cas++);
        if (min(R,C) == 1) work1();
        else
        if (min(R,C) == 2) work2();
        else work3();
    }
}
