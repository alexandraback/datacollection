#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    long long r, p; cin >> r >> p;
    long long low = 0, hi = min(p / (2*r) + 1, 1000000001LL);
    while (hi - low > 1) {
      long long mid = (low + hi) / 2;
      if ((2*r + 2*mid - 1) * mid <= p) low = mid;
      else hi = mid;
    }
    cout << "Case #" << c << ": " << low << endl;
  }
  return 0;
}
