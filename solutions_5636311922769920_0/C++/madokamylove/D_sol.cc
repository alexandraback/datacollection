#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);
        
        if (K == 1) {
            printf("Case #%d: %d\n", cas, 1);
        } else if (C == 1) {
            if (S < K) {
                printf("Case #%d: IMPOSSIBLE\n", cas);
            } else {
                printf("Case #%d:", cas);
                for (int i = 1; i <= K; i++) {
                    printf(" %d", i);
                }
                puts("");
            }
        } else {
            if (S < (K + 1) / 2) {
                printf("Case #%d: IMPOSSIBLE\n", cas);
            } else {
                printf("Case #%d:", cas);
                int cnt = K / 2;
                for (int i = 1; i <= (K + 1) / 2; i++) {
                    printf(" %d", cnt + 1);
                    cnt += K + 1;
                }
                puts("");
            }
        }
    }
    return 0;
}