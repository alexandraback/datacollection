#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int T, C = 1;

  cin >> T;
  long long r, t;
  while (T-- && cin >> r >> t) {
    long long ts = sqrt((long double)t);
    while ((ts+1)*(ts+1) <= t)
      ++ts;

    long long low = 1, hi = ts;
    hi = min(hi, t/(2 + 2*r - 1) + 1);

    while (low + 1 < hi) {
      long long mid = (low + hi)/2;

      if (mid*(2*r + 2*mid - 1) > t) {
        hi = mid;
      } else {
        low = mid;
      }
    }

    cout << "Case #" << C++ << ": " << low << endl;
  }
}
