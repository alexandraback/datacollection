#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

int main(void) {
  
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    double C, F, X; cin >> C >> F >> X;
    double ans = X/2, elapsed = 0;
    int farms = 0;
    while (true) {
      double ans2 = elapsed + C/(2+farms*F) + X/(2+(farms+1)*F);
      if (ans2 > ans) break;
      ans = ans2;
      elapsed += C/(2+farms*F);
      farms++;
    }
    printf("Case #%d: %.7f\n", t, ans);
  }
}
