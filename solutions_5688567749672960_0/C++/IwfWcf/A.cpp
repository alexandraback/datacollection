#include <stdio.h>
#include <algorithm>

using namespace std;

const long long N = 1000010;

long long f[N];

long long reverse(long long x)
{
    long long ret = 0;
    while (x > 0)
    {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}

long long solve(long long n)
{
    if (f[n] > 0)
    {
        return f[n];
    }
    long long ret = n;
    long long reverse_n = reverse(n);
    if (reverse_n < n && reverse(reverse_n) == n)
    {
        ret = min(ret, solve(reverse_n) + 1);
    }
    ret = min(ret, solve(n - 1) + 1);
    return f[n] = ret;
}

int main()
{
    for (int i = 1; i < 21; i++)
    {
        f[i] = i;
    }
    for (int i = 21; i < N; i++)
    {
        f[i] = solve(i);
    }

    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++)
    {
        long long n;
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", cases, solve(n));
        continue;
        if (n < 21)
        {
            printf("Case #%d: %lld\n", cases, n);
            continue;
        }
        long long count = 12;
        long long now = 12;
        while (now < n)
        {
            long long reverse_now = reverse(now);
            if (reverse_now <= now || reverse_now > n)
            {
                now = now + 1;
            }
            else
            {
                long long next = now + 1;
                long long reverse_next = reverse(next);
                if (reverse_next > reverse_now && reverse_next <= n)
                {
                    now = now + 1;
                }
                else
                {
                    now = reverse_now;
                }
            }
            count++;
            printf("now: %lld count: %lld\n", now, count);
        }
        printf("Case #%d: %lld\n", cases, count);
    }
    return 0;
}
