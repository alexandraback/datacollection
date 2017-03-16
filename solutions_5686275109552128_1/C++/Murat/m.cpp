#include<bits/stdc++.h>
  
using namespace std;

template<class T> inline T sqr(const T& a) { return a * a; }
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
constexpr ld EPS = 1e-9;
constexpr ld PI = 2 * acos(0.0);
constexpr int N = 1010;

int p[N];

int main() {
  int tests;
  scanf("%d", &tests);
  for (int it = 1; it <= tests; ++it) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &p[i]);
      ans = max(ans, p[i]);
    }
    int tmax = ans;
    for (int t = 1; t <= tmax; ++t) {
      int special = 0;
      for (int i = 0; i < n; ++i) {
        if (p[i] <= t)
          continue;
        int d = p[i] / t;
        while ((p[i] + d - 1) / d > t)
          ++d;
        special += d - 1;
      }
      //printf("t = %d, special = %d\n", t, special);
      ans = min(ans, t + special);
    }
    printf("Case #%d: %d\n", it, ans);
  }
  return 0;
}
