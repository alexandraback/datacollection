#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fore(i,n) for(int i = 0; i< n ; i++ )
#define lop(i,n) for(int i = 1 ; i<=n ; i++ )
#define ops(i,n) for(int  i = n-1 ; i>=0 ; i-- )
#define forall( it,g )  for( typeof(g.begin()) it=g.begin();it!=g.end();it++ )
#define PI  3.141592653589793
#define mod  1000000007
#define inf 2000000000
#define INF -2000000000000000
#define modulo 1000000009
#define MH 1234533333333337
#define MH2 7779845079489377
#define enter endl
//ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
typedef vector <int> vi;
typedef vector <vector <int> > vv;
typedef vector <pair <int,int > >vp;
typedef vector <vector <pair <int ,int > > > vvp;
typedef vector <pair <int ,pair <int ,int > > > vpp;
typedef pair<int,int> pp;
typedef long long ll;
typedef unsigned long long ull;
const int M = 1005;
vi g[M], gr[M];
bool visit[M], gg[M][M];
int n, target, ma;
void cycle(int u, int d)
{
        fore(i, g[u].size())
        {
                int v = g[u][i];
                if(!visit[v])
                {
                        visit[v] = true;
                        cycle(v, d + 1);
                        visit[v] = false;
                }
                else if(v == target && d > 1)
                {
                        ma = max(ma, d + 1);
                }
        }
}
int dfs(int u)
{
        int ans = 0;
        fore(i, gr[u].size())
        {
                int v = gr[u][i];
                if(!visit[v])
                {
                        visit[v] = true;
                        ans = max(ans, 1 + dfs(v));
                        visit[v] = false;
                }
        }
        return ans;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, cases = 0;
    scanf("%d", &t);
    while(t--)
    {
                cases++;
                printf("Case #%d: ", cases);
                scanf("%d", &n);
                lop(i, n)
                {
                        int x;
                        scanf("%d", &x);
                        g[i].pb(x);
                        gr[x].pb(i);
                        gg[i][x] = true;
                }
                ma = 0;
                lop(i, n)
                {
                        target = i;
                        memset(visit, 0, sizeof visit);
                        visit[i] = true;
                        cycle(i, 0);
                }
                int m = 0;
                lop(i, n)
                {
                        for(int j = i + 1; j <= n; j++)
                        {
                                if(gg[i][j] && gg[j][i])
                                {

                                        int a = 0, b = 0;
                                        memset(visit, 0, sizeof visit);
                                        visit[i] = true, visit[j] = true, a = dfs(i);
                                        memset(visit, 0, sizeof visit);
                                        visit[i] = true, visit[j] = true, b = dfs(j);
                                        m += a + b + 2;
                                }
                        }
                }
                fore(i, n + 5)
                {
                        g[i].clear();
                        gr[i].clear();
                }
                memset(gg, 0, sizeof gg);
                cout << max(ma, m) << "\n";
    }
    return 0;
}
