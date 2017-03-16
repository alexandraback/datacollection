#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int T;
int n,jmp[1111],dp[1111];
vector<int> e[1111];

int dfs(int u){
    if(dp[u]!=-1) return dp[u];
    dp[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        dfs(v);
        dp[u]=max(dp[u],dp[v]+1);
    }
    return dp[u];
}

int res2;

int check(int start){
    set<int> mys;
    int u=start; mys.insert(u);
    int pre = -1;
    while(1){
        int v=jmp[u];
        if(v==pre || (v==start && sz(mys)==2)){
            int res = 0;
            for(int i=0; i<sz(e[u]); ++i){
                int x=e[u][i];
                if(x!=v) res=max(res, dfs(x));
            }
            return res + sz(mys);
        }
        if(v==start) res2=max(res2,sz(mys));
        if(mys.count(v)) return -1;
        mys.insert(v);
        pre = u;
        u = v;
    }
}

bool mark[1111];
vector<int> com[1111];
int cntcom;

void go(int u){
    com[cntcom].pb(u);
    mark[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(!mark[v]) go(v);
    }
    if(!mark[jmp[u]]) go(jmp[u]);
}

int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) e[i].clear();
        for(int i=1; i<=n; ++i){
            scanf("%d",&jmp[i]);
            e[jmp[i]].pb(i);
        }
        cntcom=0; reset(mark,0);
        for(int i=1; i<=n; ++i) if(!mark[i]){
            ++cntcom;
            com[cntcom].clear();
            go(i);
        }
        int res=0;
        reset(dp,-1);
        res2=0;

        for(int i=1; i<=cntcom; ++i){
            int val=0;
            for(int j=0; j<sz(com[i]); ++j){
                int u=com[i][j];
                val=max(val,check(u));
            }
            res += val;
        }
        res=max(res,res2);
        printf("Case #%d: %d\n",tt,res);

    }
}

