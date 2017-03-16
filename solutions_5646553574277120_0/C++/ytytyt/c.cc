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

int T, ti;
int V, D, C;
bool f[32], a[32], b[2][32];
bool found;

bool check(int p) {
  for (int i = 1; i <= V; ++i)
    f[i] = false;
  f[0] = true;
  int k = 0;
  int i = 1;
  while (i <= V) {
    while (i <= V && !b[1][i])
      ++i;
    if (i <= V) {
    for (int j = V; j >= 0; --j)
      if (f[j] && i + j <= V && !f[i+j]) {
        k++;
        f[i+j] = true;
        // cout << i << ' ' << i+j << endl;
        if (k == V) {
          // for (int k = 1; k <= V; ++k)
          //   if (b[1][k])
          //     cout << k << ' ';
          // cout << endl;
          return true;
        }
      }
    }
    ++i;
  }
  return false;
}

bool dfs(int p, int k) {
  if (found)
    return true;
  if (k == p) {
    if (check(p)) {
      found = true;
      return true;
    } else
      return false;
  }
  for (int i = 1; i <= V; ++i)
    if (!b[1][i]) {
      b[1][i] = true;
      if (dfs(p, k+1))
        return true;
      b[1][i] = false;
    }
  return false;
}

int solve() {
  cin >> C >> D >> V;
  found = false;
  for (int i = 1; i <= V; ++i)
    b[0][i] = false;
  int t;
  for (int i = 1; i <= D; ++i) {
    cin >> t;
    b[0][t] = true;
  }
  int ans = 0;
  while (!found) {
    for (int i = 1; i <= V; ++i)
      b[1][i] = b[0][i];
    if (dfs(ans, 0))
      break;
    ans++;
  }
  printf("Case #%d: %d\n", ti, ans);
  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
