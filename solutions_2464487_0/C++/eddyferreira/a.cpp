#include <iostream>
using namespace std;

int main(void) {
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    cout << "Case #" << tt << ": ";
    int64_t t, r;
    cin >> r >> t;
    int64_t lo = 0, hi = 10000000000ll;
    while (hi - lo > 1) {
      int64_t mid = (lo + hi) / 2;
      if (2*mid + 2*r - 1 <= t / mid)
        lo = mid;
      else
        hi = mid;
    }
    cout << lo << endl;
  }

  /*
 (r+1)^2 - r^2 = 2r + 1  4i + 1 + 2R
        N(1 + 2*R) + 2*N*(N-1) <= T
        (2N + 2R - 1) <= T/N
        2*N^2 + N(2R - 1) - T == 0
        (2R-1)^2 
  */
}
