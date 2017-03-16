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
        long long base = 1;
        for (int i = 1; i <= C - 1; ++i) base *= 1LL * K;
        for (int i = 1; i <= S; ++i) {
            printf(" %lld", base * i);
        }
        printf("\n");
    }
    return 0;
}