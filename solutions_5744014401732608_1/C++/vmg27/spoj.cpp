#include    <bits/stdc++.h>

#define     M_PI            3.14159265358979323846
#define     mod             1000000007
#define     inf             1000000000000000000
#define     mp              make_pair
#define     pb              push_back
#define     F               first
#define     S               second
#define     ll              long long
#define     pii             pair<int,int>
#define     pli             pair<ll,int>
#define     pil             pair<int,ll>
#define     pll             pair<ll,ll>
#define     si(t)           scanf("%d",&t)
#define     sii(m,n)        scanf("%d %d",&m,&n);
#define     sl(t)           scanf("%lld",&t)
#define     rep(i,n)        for(int i=0;i<n;i++)
#define     REP(i,a,b)      for(int i=a;i<=b;i++)
#define     RREP(i,a,b)     for(int i=a;i>=b;i--)
#define     N               100005

using namespace std;

int g[55][55],n;
ll dp[55];
ll m;

void dfs(int a,ll k){
    if(k <= 0) return ;
    dp[a] = 1;
    ll p = k-1;
    g[a][n] = 1;
    REP(i,a+1,n-1){
        if(dp[i] == 0){
            dfs(i,p);
        }
        if(dp[i] <= p){
            g[a][i] = 1;
            dp[a] += dp[i];
            p -= dp[i];
        }
        if(p==0) break;
    }
}

int main(){
    int t; si(t);
    REP(T,1,t){
        memset(g,0,sizeof g);
        memset(dp,0,sizeof dp);
        si(n);
        sl(m);
        dfs(1,m);
        if(dp[1] != m){
            printf("Case #%d: IMPOSSIBLE\n",T );
        }
        else{
            printf("Case #%d: POSSIBLE\n", T);
            REP(i,1,n){
                REP(j,1,n){
                    printf("%d",g[i][j] );
                }
                printf("\n");
            }
        }
    }
    return 0;   
}

