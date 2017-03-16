#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C_small-attempt0.out", "w", stdout);
    int T, N, J;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &N, &J);
        printf("Case #%d:\n", cas);
        for (int i = 0; i < J && i < 1 << (N / 2 - 2); i++) {
            int a[20], cur = i;
            for (int i = N / 2 - 2; i >= 1; i--) {
                a[i] = cur % 2;
                cur >>= 1;
            }
            a[0] = a[N / 2 - 1] = 1;
            for (int i = 0; i < N / 2; i++) {
                printf("%d", a[i]);
            }
            for (int i = 0; i < N / 2; i++) {
                printf("%d", a[i]);
            }
            for (int w = 2; w <= 10; w++) {
                long long val = 0;
                for (int i = 0; i < N / 2; i++) {
                    val = val * w + a[i];
                }
                printf(" %I64d", val);
            }
            puts("");
        }
    }
    return 0;
}