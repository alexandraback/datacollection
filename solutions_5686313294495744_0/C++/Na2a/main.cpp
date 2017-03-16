/* no greedy easy life */

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <ctime>

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef double ld;

typedef vector<int> vi;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int INF = (int) 1e9 + 7;
const int MAXN = (int) 3e5 + 7;

string a[20], b[20];
int n;

int main() {                                       
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif                                                                                          
  
  int t;
  cin >> t;
  for (int cs = 1; cs <= t; cs++) {
    printf("Case #%d: ", cs);
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    int ans = -INF;
    for (int mask = 1; mask < (1 << n); mask++) {
      vector<string> f, s;
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
          f.pb(a[i]);
          s.pb(b[i]);
        }
      }
      sort(f.begin(), f.end());
      sort(s.begin(), s.end());
      bool bad = 0;
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) continue;
        if (binary_search(f.begin(), f.end(), a[i]) && binary_search(s.begin(), s.end(), b[i])) continue;
        bad = 1;
        break;
      }
      if (!bad) ans = max(ans, n - __builtin_popcount(mask));
    }
    cout << ans << endl;
  }
  return 0;
}