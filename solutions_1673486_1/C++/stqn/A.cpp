#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long double ld;

int main() {

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int A, B;
    cin >> A >> B;
    vector<ld> p(A);
    for (int i = 0; i < A; ++i) {
      cin >> p[i];
    }
    vector<ld> pp(A + 1, 1.0);
    for (int i = 1; i <= A; ++i) {
      pp[i] = pp[i - 1] * p[i - 1];
    }
    ld ans = B + 2;
    for (int i = 0; i <= A; ++i) {
      ld _ans = B - A + 2 * i + 1;
      _ans += (1.0 - pp[A - i]) * (B + 1);
      if (ans > _ans) ans = _ans;
    }
    printf("Case #%d: %.6Lf\n", t, ans);
  }

}
