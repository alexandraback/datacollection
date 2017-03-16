#include <iostream>

using namespace std;

int main() {
  int n_tests;
  cin >> n_tests;
  for (int test = 1; test <= n_tests; ++test) {
    unsigned long long r, t;
    cin >> r >> t;
    unsigned long long MAX = 1;
    while (t / MAX >= 2 * MAX + 2 * r - 1) {
      MAX *= 2;
    }
    unsigned long long lo = 0, hi = MAX, ans = 0;
    while (lo <= hi) {
      unsigned long long k = (lo + hi) / 2;
      if (t / k >= 2 * k + 2 * r - 1) {
        ans = k;
        lo = k + 1;
      } else {
        hi = k - 1;
      }
    }
    cout << "Case #" << test << ": " << ans << endl;
  }
  return 0;
}
