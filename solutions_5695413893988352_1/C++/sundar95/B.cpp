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
#define tri pair < ll , PLL >
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
const int N = int(20) + 5;
using namespace std;
tri dp[N][2];
int vis[N][2];
string A,B;
tri solve(int l , int b)
{
        if(vis[l][b] != -1)
                return dp[l][b];
        if(l == 0)
        {
                tri ans = TRI(0,0,0);
                return ans;
        }
        vis[l][b] = 1;
        int x1,y1,x,y;
        vector < tri > answers;
        rep(x1,10)
        {
                rep(y1,10)
                {
                        if(A[l-1] == '?') x = x1;
                        else x = A[l-1] - '0';
                        if(B[l-1] == '?') y = y1;
                        else y = B[l-1] - '0';

                        int b1 = x-b < y? 1 : 0;
                        if(l == 1 && b1)continue;
                        int curdiff = (x - b - y + 10) % 10;
                        tri nextans = solve(l-1,b1);
                        tri ans = nextans;
                        if(nextans.yy == -1)continue;
                        ans.xx = ans.xx*(ll)10 + curdiff;
                        ans.yy = ans.yy*(ll)10 + x;
                        ans.zz = ans.zz*(ll)10 + y;
                        answers.pb(ans);
                        //trace6(x,y,curdiff,nextans.xx,b,l);
                }
        }
        if(sz(answers))
        {
                sort(all(answers));
                return dp[l][b] = answers[0];
        }
        else
        {
                return dp[l][b] = TRI(1 , -1 , -1);
        }
}

int main()
{
        int i,j,n,t;
        ios::sync_with_stdio(false);
        cin>>t;
        int t1 = t;
        while(t--)
        {
                rep(i,N)rep(j,2)vis[i][j] = -1;
                cin>>A>>B;
                tri ans = solve(sz(A),0);
                swap(A,B);
                memset(vis,-1,sizeof(vis));
                tri nans = solve(sz(A),0);
                if(nans.yy != -1)
                {
                        if(ans.yy == -1){ans = nans;swap(ans.yy,ans.zz);}
                        else if(ans > nans){ ans = nans; swap(ans.yy,ans.zz);}
                }
                string y,z;
                stringstream ss;ss<<ans.yy;ss>>y;
                stringstream ss1;ss1<<ans.zz;ss1>>z;
                //trace2(ans.yy,ans.zz);
                while(sz(y) < sz(A)) y = "0" + y;
                while(sz(z) < sz(A)) z = "0" + z;
                cout<<"Case #"<<t1-t<<": "<<y<<" "<<z<<endl;
        }
}
