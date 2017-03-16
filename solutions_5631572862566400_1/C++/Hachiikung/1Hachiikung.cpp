/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i,FN) for(int i=0;i<FN;i++)
#define FOR(i,ST,FN) for(int i=ST;i<=FN;i++)
#define FORD(i,FN,ST) for(int i=FN;i>=ST;i--)
#define FORX(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();i++)
#define pause system("pause")
#define S scanf
#define P printf
#define X first
#define Y second
#define pb push_back
#define PII pair<int,int>
#define mp make_pair
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN(1005);

int a[MAXN], visited[MAXN], ans, cycle;

vector<int>g[MAXN];

int dfs(int node,int v){

    visited[node] = 1;

    int ret = 0;

    REP(i,g[node].sz)
    {
        int u = g[node][i];
        if(u != v && !visited[u])
            ret = max(ret, dfs(u, v));
    }

    return ret+1;

}

void dfs2(int node){

    visited[node] = 2;

    int u = a[node];

    if(!visited[u])
    {
        dfs2(u);
    }

    else if(visited[u] == 2)
    {
        int v = u;

        cycle = 0;

        while(v != node)
        {
            cycle++;
            v = a[v];
        }

        cycle++;

        ans = max(ans, cycle);

    }

    visited[node] = 1;

}

void solve(int test){

    int n;
    S("%d",&n);

    FOR(i,1,n)
    {
        g[i].clear();
        visited[i] = 0;
    }

    FOR(i,1,n)
    {
        S("%d",&a[i]);
        g[i].pb(a[i]);
        g[a[i]].pb(i);
    }

    ans = 0;

    FOR(i,1,n)
    {
        if(!visited[i] && a[a[i]] == i)
        {
            ans += (dfs(i,a[i]) + dfs(a[i],i));
        }
    }

    FOR(i,1,n)
    {
        if(!visited[i])
        {
            dfs2(i);
        }
    }

    P("Case #%d: %d\n",test,ans);

}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);

    FOR(i,1,t)
        solve(i);

}
