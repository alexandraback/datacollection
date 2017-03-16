#include <cstdio>
long long gcd(long long a, long long b)
{
    return a == 0 ? b : gcd(b % a, a);
}
int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("A-large.txt","w",stdout);
    int t,cc;
    long long p,q,g,qq;
    scanf("%d",&t);
    for (cc=1;cc<=t;cc++)
    {
        printf("Case #%d: ",cc);
        scanf("%lld/%lld",&p,&q);
        //printf("%lld %lld\n",p,q);
        g=gcd(p,q);
        p/=g;
        q/=g;
        qq=q;
        while (qq%2==0)
        {
            qq/=2;
        }
        if (qq!=1)
        {
            printf("impossible\n");
            continue;
        }
        int ans=0;
        while (p<q)
        {
            ans++;
            p*=2;
        }
        if (ans<=40)
            printf("%d\n",ans);
        else
            printf("impossible\n");
    }
    return 0;
}
