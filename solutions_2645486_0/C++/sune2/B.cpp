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

ll dp[20][20];
int v[20];

int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    int E,R,n;
    cin >> E >> R >> n;
    REP(i,n) {
      cin >> v[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0][E] = 0;
    REP(i,n) {
      REP(j,E+1) {
        if (dp[i][j] == -1) continue;
        for (int k=0; k<=j; ++k) {
          chmax(dp[i+1][min(E,j-k+R)], dp[i][j] + v[i]*k);
        }
      }
    }
    ll ans = 0;
    REP(j,E+1) chmax(ans, dp[n][j]);
    printf("Case #%d: %lld\n", cs+1, ans);
  }
}
