#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int T,n,a[1005],b[1005],c[1005];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
  memset(c,0,sizeof(c));
  int star = 0,round = 0;
  while (star < 2 * n) {
    bool add = false;
    for (int i = 0; i < n; i++) if (c[i] < 2 && b[i] <= star) {
      add = true;  round++;  star += 2 - c[i];  c[i] = 2;
    }
    if (add) continue;
    int idx = -1;
    for (int i = 0; i < n; i++) if (c[i] < 1 && a[i] <= star)
      if (idx < 0 || b[i] > b[idx]) idx = i;
    if (idx < 0) return -1;
    star++;  c[idx] = 1;  round++;
  }
  return round;
}

int main() {
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) {
    int ans = solve();
    printf("Case #%d: ", it);
    if (ans < 0) printf("Too Bad\n"); else printf("%d\n", ans);
  }
}
