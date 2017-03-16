#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

bool mat[4][4][4];
void init() {
    memset(mat, false, sizeof(mat));
    mat[0][0][0] = true;
    mat[0][1][0] = mat[0][1][1] = true;
    mat[0][2][0] = true;
    mat[0][3][0] = mat[0][3][1] = true;
    mat[1][1][0] = mat[1][1][1] = true;
    mat[1][2][0] = mat[1][2][1] = mat[1][2][2] = true;
    mat[1][3][0] = mat[1][3][1] = true;
    mat[2][2][0] = mat[2][2][2] = true;
    memset(mat[2][3], true, sizeof(mat[2][3]));
    mat[3][3][0] = mat[3][3][1] = mat[3][3][3] = true;
}
int main() {
    init();
    freopen("D-small-attempt4.in", "r", stdin);
    freopen("D-small-attempt4.out", "w", stdout);
    int t, x, r, c;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &x, &r, &c);
        if(r > c) swap(r, c);
        printf("Case #%d: ", cas);
        if(mat[r-1][c-1][x-1])
            puts("GABRIEL");
        else
            puts("RICHARD");
    }
    return 0;
}
