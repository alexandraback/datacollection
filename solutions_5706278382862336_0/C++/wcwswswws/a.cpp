#include<stdio.h>
using namespace std;

bool check(long long p)
{
    long long two=2,zero=0,one=1;
    while (p%two==zero) p/=two;
    return (p==one);
}

long long gcd(long long p,long long q)
{
    long long zero=0;
    if (q==zero) return p; else return gcd(q,p%q);
}

int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        long long p,q;
        scanf("%I64d/%I64d",&p,&q);
        long long g=gcd(q,p);
        p/=g;q/=g;
        printf("Case #%d: ",t);
        if (!check(q))
        {
            printf("impossible\n");
            continue;
        }
        int ans=0;
        while (p<q)
        {
            long long two=2;
            q/=2;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
