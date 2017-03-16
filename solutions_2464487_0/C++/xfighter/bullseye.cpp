#include <iostream>
using namespace std;

bool check(long long r, long long t, long long k) {
  if (k > t) return false;
  return k * (2 * r - 1 + 2 * k) <= t;
}

int main () {
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    long long r, t;
    cin >> r >> t;

    long long l = 1, h = 1000000000;
    while (l < h) {
      long long mid = (l + h + 1) / 2;
      if (check(r, t, mid)) {
        l = mid;
      } else {
        h = mid - 1;
      }
    }

    cout << "Case #" << c << ": " << l << endl;
  }
}
