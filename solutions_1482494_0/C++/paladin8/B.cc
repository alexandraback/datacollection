#include <iostream>
using namespace std;

int a[1010], b[1010], p[1010];

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      p[i] = 0;
    }

    int res = 0, cur = 0;
    while (cur < 2*n) {
      bool found = false;
      for (int j = 0; j < n; j++) {
        if (cur >= b[j] && p[j] < 2) {
          cur += 2 - p[j]; p[j] = 2;
          found = true;
          break;
        }
      }
      if (found) { res++; continue; }

      int ci = -1;
      for (int j = 0; j < n; j++) {
        if (cur >= a[j] && p[j] == 0 && (ci == -1 || b[j] > b[ci])) {
          ci = j;
          found = true;
        }
      }
      if (!found) { res = -1; break; }

      res++; cur++; p[ci] = 1;
    }

    if (res == -1) cout << "Case #" << c << ": Too Bad" << endl;
    else cout << "Case #" << c << ": " << res << endl;
  }
  return 0;
}
