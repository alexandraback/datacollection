#include<stdio.h>
int isPowerOfTwo(long long x)
{
  return x && (!(x&(x-1)));
}
int gcd(int n, int m)
{
    int gcd, remainder;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    gcd = m;
    return gcd;
}
int main()
{
    long long t, k, a, b, count;
    scanf("%lld", &t);
    for(k = 1; k <= t; k++)
    {
        count = 0;
        scanf("%lld/%lld", &a, &b);
        long long temp = gcd(a, b);
        a /= temp;
        b /= temp;
        if(!isPowerOfTwo(b))
        {
            printf("Case #%lld: impossible\n", k);
            continue;
        }
        long long div = a / b;
        while(div < 1)
        {
            b /= 2;
            div = a / b;
            count++;
        }
        printf("Case #%lld: %lld\n", k, count);
    }
    return 0;
}
