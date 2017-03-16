#include <stdio.h>
#include <math.h>

int main(void)
{
    int T = 0;

    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        long long r = 0;
        long long t = 0;
        scanf("%lld %lld", &r, &t);

        long long guess = (long long)sqrt((double)t);
        long long n = (guess - r - 1) / 2;
        if (n < 0)
        {
            n = 0;
        }
        while ((n + 1) * ((r << 1) + 1 + (n << 1)) <= t)
        {
            n++;
        }

        printf("Case #%d: %lld\n", i, n);
    }
}
