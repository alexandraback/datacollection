#include <bits/stdc++.h>
using namespace std;
const int N = 20;
typedef long long LL;
#define fix(x) x = x >= MOD ? x % MOD : x
const LL MAXN = 5e18;

int n,n0[2];
string f[2][N];
map<string,int>s[2];
int g[2][N];
int ans = 0;
bool u[2][N];
vector<int>edg[N];

bool state[N];//记录V2中的每个点是否被搜索过

void init()
{
    cin>>n;
    for(int i = 1;i <= n;i++) edg[i].clear();
    s[0].clear();s[1].clear();
    n0[0] = n0[1] = 0;

    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            cin>>f[j][i];
            if(s[j].find(f[j][i]) != s[j].end()) g[j][i] = s[j][f[j][i]];
            else n0[j]++ , s[j][f[j][i]] = n0[j],g[j][i] = n0[j];
        }
    }
}

void check()
{
    int cnt = 0;

    memset(u,0,sizeof(u));

    for(int i = 1;i <= n;i++)
    if(state[i])
    {
        for(int j = 0;j < 2;j++)
          u[j][ g[j][i] ] = true;
        cnt++;
    }

    for(int i = 1;i <= n;i++)
    {
        if( !u[0][g[0][i]] || !u[1][g[1][i]]) return;
    }

    ans = max(ans , n - cnt);
}

void dfs(int a)
{
    if(a == n + 1)
    {
        check();
        return;
    }
    state[a] = true;
    dfs(a + 1);
    state[a] = false;
    dfs(a + 1);
}

void work()
{
    for(int i = 1;i <= n;i++)
    {
        edg[ g[0][i] ].push_back( g[1][i] );
 //       cout<<g[0][i]<<" "<<g[1][i]<<endl;
    }
    ans = 0;
    dfs(1);
    printf("%d\n",ans);
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
        printf("Case #%d: ",i);
        init();
        work();
    }

    return 0;
}
