#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long LL;

int T, ti, r, c, w;

int solve() {
  cin >> r >> c >> w;
  int ans = 0;
  if (c % w == 0)
    ans = c / w + w - 1;
  else
    ans = c / w + w;
  printf("Case #%d: %d\n", ti, ans*r);
  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
