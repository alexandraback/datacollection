#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  freopen("A-small-attempt1.in", "r", stdin);
  freopen("A-small-attempt1.out", "w", stdout);

  int T;
  cin >> T;

  int v[105];
  for (int cas = 1; cas <= T; cas++) {
    int a, n;
    cin >> a >> n;
    int max_a = -1;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      max_a = max(max_a, v[i]);
    }

    if (a == 1) {
      cout << "Case #" << cas << ": " << n << "\n";
      continue;
    }

    sort(v, v + n);
    int idx = 0;
    while (idx < n) {
      if (v[idx] >= a)
        break;

      a += v[idx++];
    }

    if (idx == n) {
      cout << "Case #" << cas << ": 0\n";
      continue;
    }

    int add_num = 0;
    int b = a;
    while (b <= max_a) {
      b = 2 * b - 1;
      add_num++;
    }

    int res = n - idx;
    for (int k = 1; k <= add_num; k++) {
      int adds = k;
      int idx2 = idx;
      int aa = a;
      while (idx2 < n) {
        while (aa <= v[idx2] && adds > 0) {
          aa = aa * 2 - 1;
          adds--;
        }

        if (adds == 0 && aa <= v[idx2])
          break;

        aa += v[idx2++];
      }

      int tot = k - adds + n - idx2;
      res = min(res, tot);
    }

    cout << "Case #" << cas << ": " << res << "\n";

  }

  // system("pause");
  return 0;
}
