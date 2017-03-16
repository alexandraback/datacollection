#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int a, b, k;
  int ans = 0;
  cin >> a >> b >> k;
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if ((i & j) < k) ++ans;
    }
  }
  cout << ans << endl;
}

int main() {
  int c;
  cin >> c;
  for (int i=1; i<=c; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

