#include <iostream>
using ull = intmax_t;
using namespace std;

ull padding(ull num, ull base, ull len) {
  while (len--) num *= base;
  return num;
}

ull gen_num(ull beg, ull len, ull base) {
  ull r = 0;
  for (ull i = 0; i < len; ++i) {
    r *= base;
    r += beg + i;
  }
  return r;
}

int main() {
  ull t, k, c, s;
  cin >> t;

  for (ull i = 0; i < t; ++i) {
    cin >> k >> c >> s;
    printf("Case #%ju:", i + 1);
    if (s * c < k) {
      cout << " IMPOSSIBLE";
    } else {
      // Generate 012, 345, ..., where
      //   group size = C
      //   num of group = K / C
      //   remain: K % C, padding with 0
      for (ull group = 0; group < k / c; ++group) {
        cout << ' ' << gen_num(group * c, c, k) + 1;
      }
      ull remain = k % c;
      ull result = gen_num(k - remain, remain, k);
      if (k % c) cout << ' ' << result + 1;
    }
    cout << endl;
  }
  return 0;
}
