#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

int nx[1005];
bool vs[1005];
int maks[1005];
vector<int> path;

// length + cycle length
pii dfs(int u) {
  if (vs[u]) {
    int sz = 0;
    int i = SIZE(path)-1;
    while(path[i] != u) i--;
    MAX(maks[u], i);
    return mp(SIZE(path), SIZE(path) - i);
  }
  vs[u] = 1;
  path.pb(u);
  return dfs(nx[u]);
}

int main() {
  int tc;
  scanf("%d",&tc);
  while(tc--) {
    static int t = 0;
    printf("Case #%d: ", ++t);
    RESET(maks, 0);
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
      scanf("%d",&nx[i]);
    }
    //cout << "IN" << endl;

    int ans = 0;
    // Cyc
    for(int i = 1; i <= n; i++) {
      RESET(vs, 0);
      path.clear();
      pii res = dfs(i);
      MAX(ans, res.se);
      //cout << i << " " << res.fi << " " << res.se << endl;
      if (res.se == 2) MAX(ans, res.fi + maks[path.back()]);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      if (nx[nx[i]] == i) cnt += (1 + maks[i]);
    }    
    ans = max(ans, cnt);

    printf("%d\n", ans);
  }
}