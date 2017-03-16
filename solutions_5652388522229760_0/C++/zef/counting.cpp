#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int digs[10], cnt;

int calc(int n) {
  fill(digs, digs + 10, 0);
  cnt = 0;

  int revs = 0;
  while (cnt < 10 && ++revs < 100) {
    int m = n * revs;
    do {
      cnt += digs[m % 10] == 0;
      digs[m % 10] = 1;
      m /= 10;
    } while (m != 0);
  }
  return revs < 100 ? revs * n: -1;
}

int main() {
  int t, n;
  cin >> t;
  for (int caseno = 1; caseno <= t; caseno++) {
    cin >> n;
    int ans = calc(n);
    if (ans >= 0) {
      printf("Case #%i: %i\n", caseno, ans);
    } else {
      printf("Case #%i: INSOMNIA\n", caseno);
    }
  }
}
