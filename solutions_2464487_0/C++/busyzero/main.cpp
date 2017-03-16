#include <cmath>
#include <cstdio>

using namespace std;

long long solve(long long r, long long t) {
    long long MAX = 0x7fffffffffffffff;
    long long low = 1, high = sqrt(t / 2) + 10;
    while (low + 1 != high) {
        long long n = low + (high - low) / 2;
        if (2 * n + 2 * r - 1 > MAX / n) {
            high = n;
            continue;
        }
        if (2 * n * n + (2 * r - 1) * n <= t) {
            low = n;
        } else {
            high = n;
        }
    }
    return low;
}

int main()
{
    //freopen("A-small-attempt1.in",  "r", stdin);
    //freopen("out.txt", "w", stdout);

    int TT;
    long long r, t;

    scanf("%d", &TT);
    int cs = 1;
    while (TT-- > 0) {
        scanf("%lld%lld", &r, &t);
        //printf("%lld === %lld\n", r, t);
        printf("Case #%d: %lld\n", cs++, solve(r, t));
    }

    return 0;
}
