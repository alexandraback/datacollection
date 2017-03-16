#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define _clr(x) memset(x, 0, sizeof(x))
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP_1(i, n) for (int i = 1; i <= (n); i++)
#define INC(i, a, b) for (int i = (a); i <= (b); i++)
#define DEC(i, a, b) for (int i = (a); i >= (b); i--)
const int N = 111;
int mat[N][N], colDU[N][N], colUD[N][N], rowRL[N][N], rowLR[N][N];

void PRE(int n, int m) {
    _clr(colDU);
    _clr(colUD);
    _clr(rowLR);
    _clr(rowRL);
    REP_1(i, n) REP_1(j, m) scanf("%d", &mat[i][j]);
    REP_1(i, n) REP_1(j, m) colUD[i][j] = max(mat[i][j], colUD[i - 1][j]), rowLR[i][j] = max(mat[i][j], rowLR[i][j - 1]);
    DEC(i, n, 1) DEC(j, m, 1) colDU[i][j] = max(mat[i][j], colDU[i + 1][j]), rowRL[i][j] = max(mat[i][j], rowRL[i][j + 1]);
}

bool check(int n, int m) {
    REP_1(i, n) REP_1(j, m) {
        if (colUD[i][j] <= mat[i][j] && colDU[i][j] <= mat[i][j]) continue;
        if (rowLR[i][j] <= mat[i][j] && rowRL[i][j] <= mat[i][j]) continue;
        return false;
    }
    return true;
}

int main() {
//    freopen("B-large.in", "r", stdin);
//    freopen("B-large.out", "w", stdout);
    int T, n, m;
    scanf("%d", &T);
    REP_1(cas, T) {
        scanf("%d%d", &n, &m);
        PRE(n, m);
        printf("Case #%d: ", cas);
        if (check(n, m)) puts("YES");
        else puts("NO");
    }
    return 0;
}



