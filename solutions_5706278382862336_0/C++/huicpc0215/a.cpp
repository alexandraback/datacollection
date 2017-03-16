#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define DEBUG

long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
long long p,q,tmp;
int main()
{
#ifdef DEBUG
    freopen("test.in","r",stdin);
    freopen("hehehe.out","w",stdout);
#endif
    int t,casecnt=1;scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",casecnt++);
        scanf("%lld/%lld",&p,&q);
        tmp = gcd(q,p);
        tmp = q/tmp;
        while(!(tmp&1)) tmp/=2;
        if(tmp!=1ll)printf("impossible\n");
        else
        {
            tmp=gcd(p,q);
            p/=tmp;
            q/=tmp;
            int ans = 1;
            while( p < q/2 )
            {
                ans ++; p*=2;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
