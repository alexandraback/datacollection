#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int z = 1; z <= T; z++) {
        long long r, t;
        scanf("%lld %lld", &r, &t);

        long long lo = 0, hi = 1000000000000000000LL;
        while (lo < hi) {
            long long n = (lo+hi+1)/2;
            if (2*r+2*n-1 <= t/n)
                lo = n;
            else
                hi = n-1;
        }

        printf("Case #%d: %lld\n", z, lo);
    }
}
