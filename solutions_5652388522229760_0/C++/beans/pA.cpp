#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1000000+5;
LL ans[maxn];
int main()
{
    freopen("inA","r",stdin);
    freopen("outA","w",stdout);
    ans[0]=-1;
    for(LL i=1;i<maxn;i++)
    {
        LL show=0;
        for(LL j=1;;j++)
        {
            LL x=i*j;
            while(x) {show|=(1LL<<(x%10));x/=10;}
            if(show==((1<<10)-1)) {ans[i]=i*j;break;}
        }
    }
    LL T,kase=0;
    scanf("%lld",&T);
    while(T--)
    {
        LL N;
        scanf("%lld",&N);
        printf("Case #%lld: ",++kase);
        if(N==0) printf("INSOMNIA\n");
        else printf("%lld\n",ans[N]);
    }
}
