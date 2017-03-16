#include <iostream>
using ull = intmax_t;
using namespace std;

ull ipow(ull base, ull exp) {
  ull r = 1;
  while (--exp > 1) r *= base;
  return r;
}

int main() {
  ull t, k, c, s;
  cin >> t;

  for (ull i = 0; i < t; ++i) {
    cin >> k >> c >> s;
    printf("Case #%ju:", i + 1);
    for (ull j = 0; j < k; ++j) cout << ' ' << j + 1;
    cout << endl;
  }
  return 0;
}
