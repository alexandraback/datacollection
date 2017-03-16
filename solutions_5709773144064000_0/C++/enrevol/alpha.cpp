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

int main() {
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  int tt, nc = 0;
  scanf("%d", &tt);
  while (tt--) {
    double c, f, x;
    scanf("%lf %lf %lf", &c, &f, &x);
    double ans = x / 2;
    double r = 2;
    double t = 0;
    for (int i = 1; ; ++i) {
      t += c / r;
      r += f;
      double k = x / r + t;
      if (ans > k) ans = k;
      else break;        
    }
    printf("Case #%d: %.8lf\n", ++nc, ans);
  }
}
