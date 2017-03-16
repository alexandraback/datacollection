#include <stdint.h>
#include <stdio.h>

char A[5][5];
char R[4][32] = {"X won", "O won", "Draw", "Game has not completed"};
const int32_t n = 4;

bool Row(int32_t r, char a) {
    for (int32_t i = 0; i < n; i++) {
        if ((A[r][i] != a && A[r][i] != 'T') || A[r][i] == '.') return false;
    }
    return true;
}
bool Col(int32_t c, char a) {
    for (int32_t i = 0; i < n; i++) {
        if ((A[i][c] != a && A[i][c] != 'T') || A[i][c] == '.') return false;
    }
    return true;
}
bool Diag(char a, int32_t r, int32_t d) {
    for (int32_t i = 0; i < n; i++) {
        if ((A[r + i * d][i] != a && A[r + i * d][i] != 'T') || A[r + i * d][i] == '.') return false;
    }
    return true;
}
bool Four(char a) {
    for (int32_t i = 0; i < n; i++) {
        if (Row(i, a) || Col(i, a)) return true;
    }
    if (Diag(a, 0, 1) || Diag(a, 3, -1)) return true;
    return false;
}
bool Complete() {
    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < n; j++) {
            if (A[i][j] == '.') return false;
        }
    }
    return true;
}
int32_t Solve() {
    if (Four('X')) return 0;
    if (Four('O')) return 1;
    if (Complete()) return 2;
    return 3;
}
int32_t main() {
    int32_t cas = 0;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic++) {
        for (int32_t i = 0; i < n; i++) {
            scanf("%s", A[i]);
        }
        int32_t r = Solve();
        printf("Case #%d: %s\n", ic, R[r]);
    }
    return 0;
}
