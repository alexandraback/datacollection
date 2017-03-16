#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

int m,n,h[105][105],T;

void solveCase(int it) {
  bool valid = true;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) scanf("%d", &h[i][j]);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      bool able = false,flag = true;
      // horizontal cut
      for (int k = 0; k < n; k++) if (h[i][j] < h[i][k]) flag = false;
      able |= flag;
      flag = true;
      // vertical cut
      for (int k = 0; k < m; k++) if (h[i][j] < h[k][j]) flag = false;
      able |= flag;
      valid &= able;
    }
  printf("Case #%d: ", it);
  if (valid) printf("YES\n"); else printf("NO\n");
}

int main() {
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) solveCase(it);
}
