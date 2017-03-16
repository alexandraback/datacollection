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
LL n, m;
int mp[60][60];

int solve() {
  cin >> n >> m;
  printf("Case #%d: ", ti);
  // cout << m << ' ' << (1<<(n-2)) << endl;
  if (m > (1<<(n-2))) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  mp[0][n-1] = 1;
  cout << "POSSIBLE" << endl;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      mp[i][j] = 1;
  m--;
  for (int i = 1; i < n-1; ++i) {
    mp[0][i] = ((m >> (n-i-1))&1);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << mp[i][j];
    cout << endl;
  }

  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
