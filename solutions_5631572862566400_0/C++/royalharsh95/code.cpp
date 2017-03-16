#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
 
using namespace std;

#define MAX 1000008
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define M_PI 3.14159265358979323846
#define mp make_pair
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INT_MAX 2147483647
#define pb push_back
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define itr(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> lli;
typedef pair<int,pii> i3;
 
vector<vector<int> > v;
 
vector<int> tsort;
 
int n,h;
bool vis[1004];
int dp=0,dpi=0;
void dfs(int i,int dpth){
if(vis[i])return;
vis[i]=1;
 
for(int j=0; j<v[i].size(); j++)
    if(!vis[v[i][j]]){
            if((dpth+1)>dp){
                dp=dpth+1;
                 dpi=i;
            }
     dfs(v[i][j],dpth+1);
 }
  
}
 
 
 
 
 
int main()
{
    read; write;
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
     v=   vector<vector<int> > (1003);
            dp=0;dpi=0;
       int d,mx=0;
       cin>>n;
       for(int j=1; j<=n; j++){
            cin>>d;
         v[j].push_back(d);
        v[d].push_back(j);
       }
      memset(vis,0,sizeof vis);
      for(int j=1; j<=n; j++){
        if(!vis[j])
            dfs(j,1);
      }
 
      memset(vis,0,sizeof vis);
 
dfs(dpi,1);
 
 
 
cout<<"Case #"<<i<<": "<<dp<<endl;
    }
    return 0;
}