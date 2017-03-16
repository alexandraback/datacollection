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
const ld EPS = 1e-9;



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
  cout.setf(ios::fixed);
  cout.precision(20);
  for (int ti = 0; ti < ts; ++ti) {
    int k, l, n;
    string s, t;
    cin >> k >> l >> n;
    cin >> s >> t;

    int u[256], v[256];
    ld f[256];
    memset(u, 0, sizeof u);
    memset(v, 0, sizeof v);
    memset(f, 0, sizeof f);
    for (int i = 0; i < k; ++i) {
      ++u[(int)s[i]];
      ++f[(int)s[i]];
    }
    for (int i = 0; i < l; ++i) {
      ++v[(int)t[i]];
    }
    bool can = true;
    for (int i = 0; i < 256; ++i) {
      f[i] = (ld) f[i] / k;
      if (v[i] && !u[i]) {
        can = false;
      }
    }
    ld ans = 0;
    if (can) {
      for (int i = 1; i <= l; ++i) {
        bool mt = true;
        for (int j = 0; i + j < l; ++j) {
          if (t[j] != t[i + j]) {
            mt = false;
            break;
          }
        }
        if (mt) {
          ans = (n - l) / i + 1;
          break;
        }
      }
    }
    ld p = 1;
    for (int i = 0; i < l; ++i) {
      p *= f[(int)t[i]];
    }
    ans -= (n - l + 1) * p;
    cout << "Case #" << ti + 1 << ": " << ans << "\n";
  }
  return 0;
}
