#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
  return (y == 0) ? x : gcd(y, x % y);
}

ll P, Q;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    scanf("%lld/%lld", &P, &Q);
    ll g = gcd(P, Q);
    P /= g;
    Q /= g;
    cout << "Case #" << t << ": ";
    if ((Q & (Q - 1)) != 0) {
      cout << "impossible" << endl;
    } else {
      int x = 0;
      while ((Q >> x) > P) x++;
      cout << x << endl;
    }
  }
}