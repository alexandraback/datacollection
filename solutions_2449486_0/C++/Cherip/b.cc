#include <stdio.h>

const int MMAX = 101;
int mat[MMAX][MMAX];
int n,m;

int row_ok(int x, int val) {
    for (int i = 0; i < m; i++) {
        if (mat[x][i] > val) return 0;
    }
    return 1;
}

int col_ok(int x, int val) {
    for (int i = 0; i < n; i++) {
        if (mat[i][x] > val) return 0;
    }
    return 1;
}

int reduce() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row_ok(i, mat[i][j]) == 0 &&
                col_ok(j, mat[i][j]) == 0)
                return 0;
        }
    }
    return 1;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("result.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int idx = 0; idx < t; idx++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &mat[i][j]);
                mat[i][j] = mat[i][j];
            }
        }

        printf("Case #%d: ", idx+1);
        if (reduce()) printf("YES\n");
        else printf("NO\n");
    }
}
