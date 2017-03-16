#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int ntests, n, a[1000];

int main() {
  freopen("B-small-attempt2.in", "r", stdin);
  freopen("B-small-attempt2.out", "w", stdout);
  cin >> ntests;
  for (int test = 1; test <= ntests; ++test) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int maxv = *max_element(a, a + n);
    int res = maxv;
    for (int i = 1; i <= maxv; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        cnt += (a[j] + i - 1) / i - 1;
      }
      res = min(res, cnt + i);
    }
    cout << "Case #" << test << ": " << res << endl;
  }
  return 0;
}
