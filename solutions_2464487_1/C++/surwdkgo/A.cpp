#include <stdio.h>

long long calc(long long n, long long r) {
    double p = (double) n * (2.0 * r + 1) + 2.0 * n * (n - 1.0);
    if (p > 3e18) return 1ll << 62;
    else return n*(2*r+1) + 2*n*(n-1);
}

int main() {
    int casN;
    scanf("%d", &casN);

    long long r, t;
    long long L, R, M;
    for (int casI = 0; casI < casN; casI++) {
        scanf("%lld%lld", &r, &t);
        L = 0;
        R = t;
        while (L+1 < R) {
            M = (L+R) / 2;
            if (calc(M, r) <= t) L = M;
            else R = M;
        }
        printf("Case #%d: %lld\n", casI+1, L);
    }
}
