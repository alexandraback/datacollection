#include <iostream>
#include <vector>
using namespace std;

typedef long double ld;
typedef long long ll;

ld C, F, X;

ld f(ll x) {
  ld res = 0;
  for (int i = 0; i < x; ++i) {
    res += C/(2 + i*F);
  }
  res += X/(2 + x*F);
  return res;
}

ld solve() {
  cin >> C >> F >> X;
  ll ini = 0, fin = 1e6;
  while (fin - ini >= 10) {
    ll m1 = (2*ini + fin)/3, m2 = (ini + 2*fin)/3;
    ld a1 = f(m1), a2 = f(m2);
    if (a1 < a2) fin = m2 - 1;
    else ini = m1 + 1;
  }
  ld best = f(ini);
  for (int i = ini + 1; i <= fin; ++i) best = min(best, f(i));
  return best;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(7);
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve() << endl;
  }
}
