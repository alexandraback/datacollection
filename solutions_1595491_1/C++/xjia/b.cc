#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  for (int tcase = 1; tcase <= T; tcase++) {
    int ans = 0;
    int N, S, p; cin >> N >> S >> p;
    for (int i = 0; i < N; i++) {
      int t; cin >> t;
      int x = t / 3, y = t % 3;
      if (x >= p) ans++;
      else {
        if (y == 0) {
          if (x == p-1 && p-2 >= 0 && S > 0) {
            ans++;
            S--;
          }
        } else if (y == 1) {
          if (x >= p-1 && p-1 >= 0) ans++;
        } else if (y == 2) {
          if (x >= p-1 && p-1 >= 0) ans++;
          else if (x == p-2 && p-2 >= 0 && S > 0) {
            ans++;
            S--;
          }
        }
      }
    }
    cout << "Case #" << tcase << ": " << ans << endl;
  }
  return 0;
}

