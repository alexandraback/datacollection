#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mi(ll n,ll k)
{
    ll ret=1;
    while(k--) ret*=n;
    return ret;
}

int main()
{
    freopen("D-small-attempt2.in","r",stdin);
    freopen("D-small-attempt2.out","w",stdout);
    ll T;
    scanf("%lld",&T);
    for(ll cas=1;cas<=T;++cas)
    {
        ll K,C,S;
        scanf("%lld%lld%lld",&K,&C,&S);
        ll tmp=mi(K,C-1);
        printf("Case #%lld:",cas);
        if(K==1) {printf(" 1\n");continue;}
        for(ll i=1;i<=K;++i)
        {
            ll tt=tmp;
            ll o=0;
            while(tt)
            {
                if(tt!=1) o+=tt*(i-1);
                else o+=i;
                tt/=K;
            }
            printf(" %lld",o);
        }
        printf("\n");
    }
    return 0;
}
