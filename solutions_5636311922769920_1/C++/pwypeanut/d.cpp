#include <bits/stdc++.h>
using namespace std;

int TC, K, C, S;

long long power(long long base, long long p) {
    long long ans = 1;
    for (int i = 0; i < p; i++) ans *= base;
    return ans;
}

int main() {
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d%d%d", &K, &C, &S);
        if (S * C < K) {
            printf("Case #%d: IMPOSSIBLE\n", tc);
            continue;
        } else {
            long long a[105];
            memset(a, 0, sizeof(a));
            for (int i = 0; i < K; i++) a[i/C] += power(K, i % C) * i;
            printf("Case #%d:", tc);
            for (int i = 0; i <= (K - 1) / C; i++) printf(" %lld", a[i] + 1);
            printf("\n");
        }
    }
}
