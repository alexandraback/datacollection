#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

int n,m,k;
int v[10];
int prod[10];
int num[1<<3];
int ans[10];
double ansprob;

void solve() {
  double prob = 1;
  REP(S,1<<n) num[S] = 0;
  REP(i,k) {
    double tmp = 0;
    REP(S,1<<n) {
      int p = 1;
      REP(j,n) {
        if (S>>j&1) p*= v[j];
      }
      if (p == prod[i]) {
        tmp += 1.0/(1<<n);
      }
    }
    prob *= tmp;
  }
  if (chmax(ansprob,prob)) {
    REP(i,n) {
      ans[i] = v[i];
    }
  }
}

void dfs(int now) {
  if (now == n) {
    solve();
    return;
  }
  for (int i=2; i<=m; ++i) {
    v[now] = i;
    dfs(now+1);
  }
}

int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    printf("Case #%d:\n", cs+1);
    int r;
    cin >> r >> n >> m >> k;
    REP(i,r) {
      REP(j,k) {
        cin >> prod[j];
      }
      ansprob = -1;
      dfs(0);
      REP(i,n) cout << ans[i];
      cout << endl;
    }
  }
}
