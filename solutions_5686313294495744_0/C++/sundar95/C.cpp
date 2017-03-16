#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define s(n) scanf("%d",&n)
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define PLL pair<ll,ll>
#define inf 1000*1000*1000+5
#define v(a,size,value) vi a(size,value)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair < int , PII >
#define TRI(a,b,c) mp(a,mp(b,c))
#define xx ff
#define yy ss.ff
#define zz ss.ss
#define in(n) n = inp()
#define vii vector < PII >
#define vll vector< PLL >
#define viii vector < tri >
#define vs vector<string>
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define ok if(debug)
#define trace1(x) ok cerr << #x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                     << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                    << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)
ll MOD = int(1e9) + 7;

int debug = 1;
const int N = int(1e3) + 5;
using namespace std;
string a[N],b[N];
vi nei[N];
int seen[N],leftof[N];
int dfs(int u)
{
        int i;
        if(seen[u])return 0;
        seen[u] = 1;
        rep(i,sz(nei[u]))
        {
                if(leftof[nei[u][i]] == -1 || dfs(leftof[nei[u][i]]))
                {
                        leftof[nei[u][i]] = u;
                        return 1;
                }
        }
        return 0;
}
int bip(int l,int r)
{
        memset(leftof,-1,sizeof(leftof));
        int i;
        int ret = 0;
        f(i,1,l+1)
        {
                memset(seen,0,sizeof(seen));
                if(dfs(i))
                        ret++;
        }
        return ret;
}
int main()
{
        int i,j,n,t;
        ios::sync_with_stdio(false);
        cin>>t;
        int t1 = t;
        while(t--)
        {
                cin>>n;
                map < string , int > fi , se;
                rep(i,N)nei[i].clear();
                rep(i,n)
                {
                        cin>>a[i]>>b[i];
                        fi[a[i]]++;
                        se[b[i]]++;
                }
                int ans = n;
                set < string > of , os;
                map < string , int > indf, inds;
                int c1 = 1 ,c2 = 1;
                rep(i,n)
                {
                        if(fi[a[i]] == 1 || se[b[i]] == 1)
                        {
                                of.insert(a[i]);
                                os.insert(b[i]);
                                ans--;
                        }
                }
                rep(i,n)
                {
                        if(fi[a[i]] == 1 || se[b[i]] == 1)continue;
                        if(of.count(a[i]) && os.count(b[i]))continue;
                        if(!of.count(a[i]) && !indf[a[i]])indf[a[i]] = c1++;
                        if(!os.count(b[i]) && !inds[b[i]])inds[b[i]] = c2++;
                        if(!of.count(a[i]) && !os.count(b[i])) nei[indf[a[i]]].pb(inds[b[i]]);
                }
                ans -= (c1 - 1 + c2 - 1 - bip(c1,c2));
                cout<<"Case #"<<t1-t<<": "<<ans<<endl;

        }
}
