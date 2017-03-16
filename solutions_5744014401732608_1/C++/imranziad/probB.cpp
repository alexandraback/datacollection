#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

LL n, k;
LL g[60][60];
int mx;
LL d[60];

LL dfs(int u)
{
    if(u == n) return 1;
    if(d[u] != -1) return d[u];
    int i, j;
    LL ret = 0;

    FOR(i,1,n)
    {
        if(g[u][i] == 1)
        {
            ret += dfs(i);
        }
    }

    return (d[u] = ret);
}

int check()
{
    mem(d,-1);
    return dfs(1);
}
/*
bool solve(int idx, int mask)
{
    if(idx == n)
    {
        if(check()) return true;
        return false;
    }

    if(vis[idx][mask])
    {
        return dp[idx][mask];
    }

    int i, j, z, t;
    vis[idx][mask] = 1;

    t = n-idx;
    z = 1<<(n-idx);

    FOR(i,1,z)
    {
        FOR(j,0,t-1)
        {
            if(i & (1<<j))
            {
                g[idx][idx+j+1] = 1;
            }
        }

        if(solve(idx+1, i))
        {
            dp[idx][mask] = true;
            return true;
        }

        FOR(j,0,t-1)
        {
            if(i & (1<<j))
            {
                g[idx][idx+j+1] = 0;
            }
        }
    }

    dp[idx][mask] = false;

    return false;
}
*/
bool go(int idx)
{
    if(idx == n) return (check() == k);
    if(check() == k) return true;

    int i, j;

    i = idx+1;

    while(i <= n && check() > k)
    {
        g[idx][i] = 0;

        int w = check();
        if(w == k) return true;
        if(w < k) g[idx][i] = 1;
        i++;
    }

    if(check() == k) return true;

    return go(idx+1);
}

int main()
{
    //READ("input.txt");
    //READ("B-large.in");
    //WRITE("B-large.out");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, i, j, cnt, sum;
    string s;

    cin >> cases;

    while(cases--)
    {
        cin >> n >> k;

        mem(g,0);

        LL x = n-2;

        if(k > (1LL<<x))
        {
            cout << "Case #" << ++caseno << ": " << "IMPOSSIBLE" << NL;
            continue;
        }

        FOR(i,1,n-1)
        {
            FOR(j,i+1,n)
                g[i][j] = 1;
        }

        bool ans = go(1);
        if(ans) s = "POSSIBLE";
        else s = "IMPOSSIBLE";

        cout << "Case #" << ++caseno << ": " << s << NL;

        if(ans)
        {
            FOR(i,1,n)
            {
                FOR(j,1,n)
                    cout << g[i][j];
                cout << NL;
            }
        }
    }

    return 0;
}




