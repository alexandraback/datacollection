#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef map<ll, int> MLLI;

ll reverse(ll n) {
  ll x = 0;
  while (n) {
    x *= 10;
    x += n%10;
    n /= 10;
  }
  return x;
}

int digits(ll n) {
  int d = 0;
  while (n) {
    ++d;
    n /= 10;
  }
  return d;
}

ll upper(ll n) {
  int d = digits(n);
  for (int i = 0; i < (d)/2; ++i) n /= 10;
  return n;
}

ll lower(ll n) {
  int d = digits(n);
  ll x = 1;
  for (int i = 0; i < d/2; ++i) x *= 10;
  return n % x;
}

ll p10(ll n) {
  ll x = 1;
  while (n--) {
    x *= 10;
  }
  return x;
}

ll costToNdigits(ll d) {
  if (d < 2) return 0;
  if (d == 2) return 10;
  ll c = 29;
  for (ll i = 4; i <= d; ++i) {
    ll len = (i)/2;
    ll n = p10(len)-1;
    n += p10(i-len-1);
    c += n;
  }
  return c;
}

ll calc(ll x) {
  if (x < 20) return x;

  ll d = digits(x);
  ll cost = costToNdigits(d);

  ll up = reverse(upper(x));
  if (lower(x) == 0 && up == 1) {
    return cost;
  }
  if (x%10 == 0) {
    return calc(x-1)+1;
  }
  if (d&1) {
    ll up2 = reverse(upper(x)/10);
    if (up2 == 1 && up > 1) --cost;
  }

  if (up > 1) cost += up;
  cost += lower(x);

  return cost;
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    ll x;
    cin >> x;
    cout << "Case #" << ++ncase << ": " << calc(x) << endl;
  }
}
