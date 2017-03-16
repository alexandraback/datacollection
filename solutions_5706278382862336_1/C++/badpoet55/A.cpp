#include <cstdio>
#include <iostream>

long long gcd(long long a, long long b)
{
    long long m = a % b;
    while (b)
    {
        m = a % b;
        a = b;
        b = m;
    }
    return a;
}

int workOnB(long long b)
{
    int k = 0;
    while (b % 2 == 0)
    {
        k++;
        b /= 2;
    }
    if (b > 1) return -1; else return k;
}

int main()
{
    long long a, b;
    int tc;
    scanf("%d", &tc);
    for (int tid = 1; tid <= tc; tid++)
    {
        scanf("%lld/%lld", &a, &b);
        long long d = gcd(b, a);
        a /= d;
        b /= d;

        int k = workOnB(b);
        if (k == -1)
        {
            printf("Case #%d: impossible\n", tid);
        } else {
            long long a0 = 1;
            for (int i = 0; i <= 40; i++)
            {
                a0 *= 2;
                if (a < a0)
                {
                    printf("Case #%d: %d\n", tid, k - i);
                    break;
                }
            }
        }
    }
    return 0;
}
