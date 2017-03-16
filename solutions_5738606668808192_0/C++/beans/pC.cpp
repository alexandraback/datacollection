#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    freopen("inC","r",stdin);
    freopen("outC","w",stdout);
    LL T,kase=0;
    scanf("%lld",&T);
    while(T--)
    {
        LL N,J;
        scanf("%lld%lld",&N,&J);
        printf("Case #%lld:\n",++kase);
        for(LL S=(1LL<<(N/2-1));J;S++)
        {
            if(!(S&1)) continue;
            J--;
            for(LL i=N/2-1;i>=0;i--) printf("%lld",S&(1LL<<i)?1LL:0LL);
            for(LL i=N/2-1;i>=0;i--) printf("%lld",S&(1LL<<i)?1LL:0LL);
            
            for(LL base=2;base<=10;base++)
            {
                LL x=0,mul=1;
                for(LL i=0;i<N/2;i++,mul*=base) x+=S&(1LL<<i)?mul:0;
                printf(" %lld",x);
            }
            puts("");
        }
    }
}
