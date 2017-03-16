#include <cstdio>
#include <cstring>

long long gcd(long long a, long long b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

long long bitcounts(long long n)
{
    int ans=0;
    while (n)
    {
        ans+=n%2;
        n/=2;
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int CAS1;
    scanf("%d", &CAS1);
    for (int CAS=1; CAS<=CAS1; CAS++)
    {
        long long a, b;
        scanf("%I64d/%I64d", &a, &b);
        long long d=gcd(a, b);
        a/=d;
        b/=d;
        printf("Case #%d: ", CAS);
        if (a>b||bitcounts(b)!=1)
            printf("impossible\n");
        else
        {
            int ans=0;
            while (a<b)
            {
                a*=2;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
