#include <stdint.h>
#include <stdio.h>

const int32_t N = 101;
int32_t A[N][N];
int32_t n, m;

bool Complete() {
    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < m; j++) {
            if (A[i][j] != N) return false;
        }
    }
    return true;
}
bool Row(int32_t x, int32_t v) {
    for (int32_t j = 0; j < m; j++) {
        if (A[x][j] != v && A[x][j] != N) return false;
    }
    return true;
}
bool Col(int32_t y, int32_t v) {
    for (int32_t i = 0; i < n; i++) {
        if (A[i][y] != v && A[i][y] != N) return false;
    }
    return true;
}
void GetMin(int32_t *mi, int32_t *mj) {
    int32_t mn = N;
    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < m; j++) {
            if (A[i][j] < mn) {
                *mi = i;
                *mj = j;
                mn = A[i][j];
            }
        }
    }
}
bool Check(int32_t x, int32_t y) {
    bool ret = false;
    if (Row(x, A[x][y])) {
        ret = true;
        for (int32_t j = 0; j < m; j++) {
            if (j != y) {
                A[x][j] = N;
            }
        }
    }
    if (Col(y, A[x][y])) {
        ret = true;
        for (int32_t i = 0; i < n; i++) {
            if (i != x) {
                A[i][y] = N;
            }
        }
    }
    if (!ret) return false;
    A[x][y] = N;
    return true;
}
bool Solve() {
    while (true) {
        if (Complete()) return true;
        int32_t mi = 0;
        int32_t mj = 0;
        GetMin(&mi, &mj);
        //printf("min = (%d, %d)\n", mi, mj);
        if (!Check(mi, mj)) return false;
    }
}
int32_t main() {
    int32_t cas = 0;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic++) {
        scanf("%d%d", &n, &m);
        for (int32_t i = 0; i < n; i++) {
            for (int32_t j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        printf("Case #%d: %s\n", ic, Solve() ? "YES" : "NO");
    }
    return 0;
}
