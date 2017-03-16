#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

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
#define Afridi 0
#define NL printf("\n")
#define SP printf(" ")
#define loj(x) printf("Case %d:",x)
#define Loj(x) printf("Case %lld:",x)
#define debug(str,x) cout << str << " " << x << endl;
#define Max 1000000
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL ara[1005];

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("boutsmall.txt","w",stdout);
    LL t,T,i,j,n;
    sl(T);
    rep(t,T)
    {
        sl(n);
        LL mx = 0;
        rep(i,n)
        {
            sl(ara[i]);
            mx = max(mx,ara[i]);
        }
        LL best = mx;
        for(i=mx;i>0;i--)
        {
            LL extra = 0;
            for(j=1;j<=n;j++)
            {
                LL my = ara[j]/i;
                if(ara[j] % i)my++;
                extra += (my-1);
            }
            LL cur = i + extra;
            //printf("%lld banaite %lld\n",i,cur);
            best = min(best,cur);
        }
        printf("Case #%lld: %lld\n",t,best);
    }
    return Afridi;
}
