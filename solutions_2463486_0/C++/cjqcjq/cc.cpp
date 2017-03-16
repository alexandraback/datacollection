#include <stdint.h>
#include <stdio.h>

const int32_t L = 50;

char A[L + 1];

void Dfs(int32_t len, int32_t idx, int32_t sum) {
    if (idx == len / 2) {
        for (int32_t i = 0; i < len / 2; i++) {
            printf("%c", A[i]);
        }
        if (len & 1) {
            printf("%c", A[len >> 1]);
        }
        for (int32_t i = len / 2 - 1; i >= 0; i--) {
            printf("%c", A[i]);
        }
        printf("\n");
        return;
    }
    for (int32_t i = 0; i * i <= sum; i++) {
        A[idx] = i + '0';
        if (sum >= 2 * i * i) {
            Dfs(len, idx + 1, sum - 2 * i * i);
        }
    }
}
void Solve(int32_t len, int32_t sum) {
    if (len == 1) {
        printf("%c\n", A[0]);
        return;
    }
    for (int32_t i = 1; i <= sum; i++) {
        if (2 * i * i <= sum) {
            A[0] = i + '0';
            Dfs(len, 1, sum - 2 * i * i);
        }
    }
}
int32_t main() {
    for (int32_t i = 1; i <= L; i++) {
        if (i & 1) {
            for (int32_t mid = 0; mid <= 3; mid++) {
                A[i >> 1] = mid + '0';
                Solve(i, 9 - mid * mid);
            }
        } else {
            Solve(i, 8);
        }
    }
    return 0;
}
