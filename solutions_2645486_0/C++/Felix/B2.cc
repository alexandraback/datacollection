#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FR first
#define SC second

#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

template <class Ta, class Tb> inline Tb cast(Ta a) {
  stringstream ss;
  ss << a;
  Tb b;
  ss >> b;
  return b;
}

const ll LINF = 1000000000000000000LL;
const int INF = 1000000000;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int ca = 1; T--; ++ca) {
    ll e, r;
    int n;
    cin >> e >> r >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    
    vector<vector<ll> > dp(n+1, vector<ll>(e+1, 0));
    dp[0][e] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= e; ++j) {
        for (int k = 0; k <= j; ++k) {
          dp[i+1][min(e, j-k+r)] = max(dp[i+1][min(e, j-k+r)], dp[i][j]+k*v[i]);
        }
      }
    }
    ll ans = 0;
    for (int i = 0; i <= e; ++i) {
      ans = max(ans, dp[n][i]);
    }
    
    cout << "Case #" << ca << ": " << ans << endl;
  }
}
