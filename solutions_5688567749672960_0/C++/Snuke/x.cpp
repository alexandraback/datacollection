#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi& a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 1000005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int dp[MX];

void bfs(int n) {
  queue<int> q;
  dp[1] = 1;
  q.push(1);
  int x;
  auto f = [&](int y){
    if (y < n && !dp[y]) {
      dp[y] = dp[x]+1;
      q.push(y);
    }
  };
  while (sz(q)) {
    x = q.front(); q.pop();
    f(x+1);
    vi d;
    ll a = x;
    while(a){ d.pb(a%10); a /= 10;}
    a = 0;
    for (int nd : d) a = a*10+nd;
    f(a);
  }
}

struct Solver {
  void solve() {
    ll x;
    cin >> x;
    cout<<dp[x]<<endl;
  }
};

int main(){
  int ts;
  scanf("%d",&ts);
  Solver solver;
  bfs(MX-2);
  rrep(ti,ts) {
    printf("Case #%d: ",ti);
    solver.solve();
  }
  return 0;
}





