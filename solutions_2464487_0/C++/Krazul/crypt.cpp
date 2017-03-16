#include <iostream>

using namespace std;

unsigned long long f(unsigned long long r, unsigned long long i) {
  unsigned long long tmp = (2*r + 1);
  unsigned long long tmp2 = tmp * i;
  if (tmp2 / i != tmp) return ULLONG_MAX;
  unsigned long long tmp3 = 2*i*(i-1);
  if (tmp2 + tmp3 < tmp2 || tmp2 + tmp3 < tmp3) return ULLONG_MAX;
  return tmp2 + tmp3;
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    cout << "Case #" << test << ": ";
    unsigned long long r, p; cin >> r >> p;
    unsigned long long low = 1;
    unsigned long long high = 1000000000;
    while (low < high) {
      unsigned long long mid = (low + high + 1) / 2;
      if (f(r, mid) <= p) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    cout << low << endl;
  }
  return 0;
}