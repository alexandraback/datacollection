#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9
#define Afridi 0

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define NL printf("\n")
#define SP printf(" ")
#define debug(x) printf("wow  %d !!\n",x)
#define Max 1000000
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("alarge.txt","w",stdout);
    LL t,T,r,c,w;
    sl(T);
    rep(t,T)
    {
        slll(r,c,w);
        LL hit = c/w;
        /*hit += (w - 1);
        if(c % w)hit++;*/
        hit *= r;
        hit += (w - 1);
        if(c % w)hit++;
        printf("Case #%lld: %lld\n",t,hit);
    }
    return Afridi;
}
