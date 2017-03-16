#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int T,n,dp[1<<10][10][2],num;
bool e[10][10];

int solve(){
    int res=0;
    for(int start=0; start<n; ++start){
        ++num;
        dp[1<<start][start][0]=num;
        for(int mask=0; mask < (1<<n); ++mask){
            int cntbit = 0;
            for(int i=0; i<n; ++i) if(mask>>i&1) ++cntbit;
            for(int u=0; u<n; ++u) for(int state=0; state<2; ++state) if(dp[mask][u][state]==num)
                for(int v=0; v<n; ++v){
                    if(mask>>v&1){
                        if(v==start){
                            if(state || e[u][start])
                                res=max(res, cntbit);
                        }
                    }else{
                        if(state==0 && !e[u][v]) continue;
                        int newstate=0;
                        if(e[v][u]) newstate=1;
                        dp[mask|(1<<v)][v][newstate] = num;
                    }
                }

        }
    }
    return res;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    reset(dp,0);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d",&n);
        reset(e,0);
        for(int i=0; i<n; ++i){
            int v;
            scanf("%d",&v); --v;
            e[i][v]=1;
        }
        int res = solve();
        printf("Case #%d: %d\n",tt,res);
    }
}

