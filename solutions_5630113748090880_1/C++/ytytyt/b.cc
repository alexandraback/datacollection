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

bool b[3000];
int l, n;

int solve() {
  cin >> n;
  for (int i = 0; i < 3000; ++i)
    b[i] = false;
  for (int i = 0; i < 2*n-1; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> l;
      b[l] = !b[l];
    }
  }
  printf("Case #%d:", ti);
  int k = 0;
  for (int i = 0; i < 2502; ++i)
    if (b[i]) {
      cout << ' ' << i;
      ++k;
    }
  if (k != n)
    cerr << ti << ' ' << k << ' ' << n << endl;
  cout << endl;
  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
