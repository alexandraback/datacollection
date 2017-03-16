#include <bits/stdc++.h>
using namespace std;
long long ans[105], K, C, S;
int TC;
long long qexp(long long b, long long e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    long long h = qexp(b, e/2);
    h *= h;
    if (e%2==0) return h;
    else return h*b;
}
int main () {
    scanf("%d", &TC);
    for (int T = 1; T <= TC; ++T) {
        scanf("%lld%lld%lld", &K, &C, &S);
        printf("Case #%d:", T);
        if (C*S < K) {
            puts(" IMPOSSIBLE");
            continue;
        }
        memset(ans, 0, sizeof ans);
        for (int i = 0; i < K; ++i) { //query item
            long long l = i%C; //level
            ans[i/C] += i*qexp(K, l);
        }
        for (int i = 0; i <= (K-1)/C; ++i) {
            printf(" %lld", ans[i]+1);
        }
        puts("");
    }
}