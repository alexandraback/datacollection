#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
using namespace std;
#define repn(i,s,n) for (int i=int(s); i < int(n); i++)
#define rep(i,n) repn(i,0,n)
#define repd(i,n) for (int i=int(n)-1; i >= 0; i--)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef VVI Graph;
typedef long long ll;

string solve()
{
  int b;
  ll m;
  cin >> b >> m;

  ll maxPossible = 1LL << (b - 2);
  if (maxPossible < m) {
    return "IMPOSSIBLE";
  }

  stringstream ans;
  ans << "POSSIBLE\n";
  rep(i, b) {
    rep(j, i + 1) ans << "0";
    repn(j, i + 1, b - 1) ans << "1";
    if (i+1 < b) {
      if (i == 0) {
        ans << ((m == maxPossible) ? "1" : "0");
        if (m == maxPossible) m--;
      }
      else {
        ans << ((m & (1 << (i-1))) ? "1" : "0");
      }
      ans << "\n";
    }
  }
  return ans.str();
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << "Case #" << i+1 << ": " << solve() << endl;
  return 0;
}
