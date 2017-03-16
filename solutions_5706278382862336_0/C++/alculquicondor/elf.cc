#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
struct Frac {
  ll num, den;
  Frac(int n = 0, int d = 1) : num(n), den(d) {
    ll g = __gcd(abs(num), den);
    num /= g;
    den /= g;
  }
  bool operator<=(const Frac & b) const {
    return log(num) + log(b.den) <= log(b.num) + log(den) + 1e-8;
  }
  Frac operator-(const Frac & b) const {
    ll g = __gcd(den, b.den);
    return Frac(b.den / g * num - den / g * b.num, den / g * b.den);
  }
};

int main() {
  int tc;
  scanf("%d", &tc);
  for (int caso = 1; caso <= tc; ++caso) {
    printf("Case #%d: ", caso);
    int n, d, id = -1;
    scanf("%d/%d", &n, &d);
    Frac v(n, d), t(1, 2);
    for (int i = 1; i < 41 and v.num > 0; ++i) {
      if (t <= v) {
        v = v - t;
        if (id == -1)
          id = i;
        //printf("#%d  %d/%d\n", i, v.num, v.den);
      }
      t.den <<= 1;
    }
    if (v.num == 0)
      printf("%d\n", id);
    else
      puts("impossible");
  }
}
