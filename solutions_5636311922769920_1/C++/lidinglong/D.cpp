#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        printf("Case #%d: ", ca);
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);
        if (C == 1) {
            if (S < K) {
                printf("IMPOSSIBLE\n");
                continue;
            } else {
                for (int i = 1; i <= K; ++i) {
                    printf(" %d", i);
                }
                printf("\n");
                continue;
            }
        }

        if (S < (K + 1) / 2) {
            if (S < K) printf("IMPOSSIBLE\n");
            continue;
        } else {
            long long base = 1;
            for (int i = 1; i <= C - 1; ++i) {
                base *= 1LL * K;
            }
            long long pos = 1;
            for (int i = 1; i <= K; i += 2) {
                int offset = i;
                printf(" %lld", min(pos + offset, base * K));
                pos += base * 2;
            }
        }
        
        printf("\n");
    }
    return 0;
}