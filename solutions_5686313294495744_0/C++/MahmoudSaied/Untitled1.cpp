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
const int M = 1 << 16;
pair<string, string> p[17];
int dp[M], n;
map<string, int> f, s;
int ways(int mask)
{
        int m = __builtin_popcount(mask);
        if(m == n)
        {
                return 0;
        }
        if(dp[mask] != -1)
        {
                return dp[mask];
        }
        int ans = 0;
        fore(i, n)
        {
                if(((1 << i) & mask) == 0)
                {
                        int b = (f[p[i].f] > 0 && s[p[i].s] > 0);
                        f[p[i].f]++;
                        s[p[i].s]++;
                        ans = max(ans, b + ways(mask | (1 << i)));
                        f[p[i].f]--;
                        s[p[i].s]--;
                }
        }
        return dp[mask] = ans;
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
                fore(i, n)
                {
                        cin >> p[i].f >> p[i].s;
                }
                memset(dp, -1, sizeof dp);
                cout << ways(0) << "\n";
                f.clear(), s.clear();
        }
        return 0;
}
