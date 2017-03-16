/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int tests;
long long int p, q, d;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        printf("Case #%d: ", t + 1);

        scanf("%lld/%lld", &p, &q);
        d = std::__gcd(p, q);
        p /= d;
        q /= d;

        if(q & (q - 1))
        {
            puts("impossible");
            continue;
        }

        int res = 0;
        while(q > p)
        {
            ++ res;
            q /= 2;
        }

        printf("%d\n", res);
    }

    return 0;
}
