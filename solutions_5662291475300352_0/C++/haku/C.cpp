#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FILE ""

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-15;

int main() {
#ifdef HOME
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  //freopen(FILE ".in", "r", stdin);
  //freopen(FILE ".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  int ts;
  cin >> ts;
  for (int ti = 0; ti < ts; ++ti) {
    int n;
    cin >> n;
    pll a, b;
    if (n == 1) {
      int h;
      ll d, m;
      cin >> d >> h >> m;
      a = {d, m};
      b = {d, m + 1};
    } else {
      int h;
      ll d, m;
      cin >> d >> h >> m;
      a = {d, m};
      cin >> d >> h >> m;
      b = {d, m};
    }
    if (a.se > b.se) {
      swap(a, b);
    }
    int ans = (360 - a.fi + b.fi) * a.se <= (360 - b.fi) * (b.se - a.se);
    
    cout << "Case #" << ti + 1 << ": " << ans << "\n";
  }
  return 0;
}
