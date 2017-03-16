#include <iostream>
#include <algorithm>
using namespace std;
int testcase;
int n, s, p;
int g[128];
int solve() {
  int ans = 0;
  int x = 0;
  if (p == 0) {
    return n;
  } else if (p == 1) {
    for (int i = 0; i < n; ++i) {
      if (g[i]) ++ans;
    }
  } else
  for (int i = 0; i < n; ++i) {
    if (g[i] >= 3 * p - 2)
      ++ans;
    else if (g[i] >= 3 * p-4) {
      if (x < s) {
        ++x;
        ++ans;
      }
    }
  }
  return ans;
}
int main() {
  cin >> testcase;
  for (int t = 0; t < testcase; ++t) {
    cin >> n >> s >> p;
    for (int i = 0; i < n; ++i)
      cin >> g[i];
    cout << "Case #" << (t+1) << ": " << solve() << endl;
  }
}
