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

int n, k, g[60][60];
int mx;

int dfs(int u)
{
    int i, j, ret = 0;

    if(u == n)
        return 1;

    FOR(i,1,n)
    {
        if(g[u][i] == 1)
        {
            ret += dfs(i);
        }
    }

    return ret;
}

bool solve(int idx)
{
    if(idx == n)
    {
        if(dfs(1) == k) return true;
        return false;
    }

    int i, j, z, t;

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

        if(solve(idx+1)) return true;

        FOR(j,0,t-1)
        {
            if(i & (1<<j))
            {
                g[idx][idx+j+1] = 0;
            }
        }
    }

    return false;
}

int main()
{
    //READ("input.txt");
    //READ("B-small-attempt1.in");
    //WRITE("B-small-attempt1.out");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, i, j, cnt, sum;
    string s;

    cin >> cases;

    while(cases--)
    {
        cin >> n >> k;

        mem(g,0);

        if(k > (1<<(n-2)))
        {
            cout << "Case #" << ++caseno << ": " << "IMPOSSIBLE" << NL;
            continue;
        }


        bool ans = solve(1);
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




