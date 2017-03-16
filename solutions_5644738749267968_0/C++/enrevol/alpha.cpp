#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const double eps = 1e-9;

double a[1010];
double b[1010];

inline bool eq(const double& a, const double& b) { return fabs(a - b) <= eps; }
inline bool le(const double& a, const double& b) { return a < b && !eq(a, b); }

bool cmp(const double& a, const double& b) { return le(a, b); }

int main() {
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  int tt, nc = 0;
  scanf("%d", &tt);
  while (tt--) {
    printf("Case #%d: ", ++nc);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%lf", a + i);
    for (int i = 1; i <= n; ++i)
      scanf("%lf", b + i);
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + n + 1);    
    int y = 0;
    {
      int j = 1;
      for (int i = 1; i <= n; ++i) {
        while (j <= n && le(b[j], a[i])) ++j;
        if (j <= n) ++y, ++j;
      }
      y = n - y;
    }
    int x = 0;
    {
      int j = 1;
      for (int i = 1; i <= n; ++i) {
        while (j <= n && le(a[j], b[i])) ++j;
        if (j <= n) ++x, ++j;
      }
    }    
    printf("%d %d\n", x, y);
  }
}
