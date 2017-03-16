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

LL visit[50][50],dp[50][50],CS;
LL c,d,v,ara[50],n,real[50];

bool fun(LL pos,LL sum)
{
    if(pos == 0)
    {
        if(sum == 0)return 1;
        else return 0;
    }

    if(visit[pos][sum] == CS)return dp[pos][sum];

    bool p1 = 0,p2 = 0;
    if(sum - ara[pos] >= 0)p1 = fun(pos-1,sum-ara[pos]);
    p2 = fun(pos-1,sum);

    visit[pos][sum] = CS;
    return dp[pos][sum] = p1 | p2;
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("csmall.txt","w",stdout);
    LL t,T,i;
    sl(T);
    rep(t,T)
    {
        slll(c,d,v);
        rep(i,d)sl(ara[i]);
        rep(i,d)
        {
            if(ara[i] > v)break;
            n = i;
        }
        bool check[50];
        mem(check,0);
        LL cnt = 0,ans = 0;
        while(1)
        {
            if(cnt == v)break;
            for(i=1; i<=v; i++)
            {
                if(check[i] == 0)
                {
                    CS++;
                    bool my = fun(n,i);
                    if(my)
                    {
                        check[i] = 1;
                        cnt++;
                    }
                }
            }
            for(i=1;i<=v;i++)
            {
                if(check[i] == 0)
                {
                    ara[++n] = i;
                    ans++;
                    break;
                }
            }
        }
        printf("Case #%lld: %lld\n",t,ans);
    }
    return Afridi;
}
