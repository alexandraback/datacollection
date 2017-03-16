#include <algorithm>
#include <cstdio>
using namespace std;

const long long MAXP = 1LL<<40;

long long gcd(long long a, long long b)
{
    while (a && b)
        if (a > b) a %= b; else b %= a;
    return a + b;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t+1);

        long long P, Q;
        scanf("%lld/%lld", &P, &Q);

        long long g = gcd(P, Q); P /= g; Q /= g;

        if (MAXP%Q != 0) {
            printf("impossible\n");
            continue;
        }

        P *= MAXP/Q;

        long long z = MAXP;
        for (int i = 1; i <= 40; ++i) {
            z /= 2;
            if (P >= z) {
                printf("%d\n", i); break;
            }
        }
    }

    return 0;
}
