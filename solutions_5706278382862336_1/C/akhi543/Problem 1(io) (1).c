#include <stdio.h>
int isPowerOfTwo(long long x)
{
  return x && (!(x&(x-1)));
}
long long gcd(long long n, long long m)
{
    long long gcd, remainder;

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

    FILE *fp1 = fopen("in.txt", "r+");
    FILE *fp2 = fopen("out.txt", "w+");

    fscanf(fp1, "%lld", &t);
    for(k = 1; k <= t; k++)
    {
        count = 0;
        fscanf(fp1, "%lld/%lld", &a, &b);

        long long temp = gcd(a, b);
        a /= temp;
        b /= temp;

        if(!isPowerOfTwo(b))
        {
            fprintf(fp2, "Case #%lld: impossible\n", k);
            continue;
        }
        long long div = a / b;
        while(div < 1)
        {
            b /= 2;
            div = a / b;
            count++;
        }
        fprintf(fp2, "Case #%lld: %lld\n", k, count);
    }
    return 0;
}
