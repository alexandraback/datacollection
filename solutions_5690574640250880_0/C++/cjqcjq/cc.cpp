#include <stdint.h>
#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

char A[6][6];
int32_t r, c, m;

bool NoDot(char x[6][6]) {
    for (int32_t i = 0; i < r; i++) {
        for (int32_t j = 0; j < c; j++) {
            if (x[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}
void Expand(char x[6][6], int32_t i, int32_t j) {
    //printf("i = %d, j = %d\n", i, j);
    x[i][j] = 'c';
    for (int32_t ir = max(0, i - 1); ir <= min(r - 1, i + 1); ir++) {
        for (int32_t ic = max(0, j - 1); ic <= min(c - 1, j + 1); ic++) {
            if (x[ir][ic] == '*') {
                return;
            }
        }
    }
    for (int32_t ir = max(0, i - 1); ir <= min(r - 1, i + 1); ir++) {
        for (int32_t ic = max(0, j - 1); ic <= min(c - 1, j + 1); ic++) {
            if (x[ir][ic] == '.') {
                Expand(x, ir, ic);
            }
        }
    }
}
bool Check() {
    char B[6][6];
    for (int32_t i = 0; i < r; i++) {
        for (int32_t j = 0; j < c; j++) {
            if (A[i][j] == '.') {
                A[i][j] = 'c';
                memcpy(B, A, sizeof(A));
                Expand(B, i, j);
                if (NoDot(B)) {
                    return true;
                }
                A[i][j] = '.';
            }
        }
    }
    return false;
}
bool Solve() {
    for (int32_t i = 0; i < (1 << r * c); i++) {
        int32_t cc = 0;
        for (int32_t j = 0; j < r * c; j++) {
            if ((1 << j) & i) {
                cc++;
            }
        }
        if (cc == m) {
            for (int32_t i = 0; i < r; i++) {
                for (int32_t j = 0; j < c; j++) {
                    A[i][j] = '.';
                }
            }
            for (int32_t j = 0; j < r * c; j++) {
                if ((1 << j) & i) {
                    A[j / c][j % c] = '*';
                }
            }
            /*
            for (int32_t i = 0; i < r; i++) {
                printf("%s\n", A[i]);
            }
            */
            if (Check()) {
                return true;
            }
        }
    }
    return false;
}
int32_t main() {
    int32_t cas;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic ++) {
        scanf("%d%d%d", &r, &c, &m);
        printf("Case #%d:\n", ic);
        memset(A, 0, sizeof(A));
        if (Solve()) {
            for (int32_t i = 0; i < r; i++) {
                printf("%s\n", A[i]);
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
