#include <cstdio>
#include <iostream>

const int N = 57;
const int M = 2507;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);
        int cnt[M] = {0};
        for (int j = 0; j < 2 * n - 1; ++j) {
            for (int k = 0, h; k < n; ++k) {
                scanf("%d", &h);
                ++cnt[h];
            }
        }
        printf("Case #%d:", i + 1);
        int p[N], pi = 0;
        for (int j = 1; j < M; ++j) {
            if (cnt[j] & 1) {
                printf(" %d", j);
            }
        }
        if (i + 1 < T) {
            printf("\n");
        }
    }
    return 0;
}
