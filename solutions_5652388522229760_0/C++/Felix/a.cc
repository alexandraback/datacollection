#include <iostream>
#include <sstream>

using namespace std;

typedef long long ll;

int digits_bitmask(ll n) {
  int digits = 0;
  for (; n > 0; n /= 10LL) {
    int cur = int(n % 10LL);
    digits |= (1<<cur);
  }
  return digits;
}

ll solve(ll n) {
  const ll MAX_I = 100;
  int seen_bm = 0;
  ll i = 1;
  for (; i < MAX_I && seen_bm != (1<<10) - 1; ++i) {
    int digits_bm = digits_bitmask(i * n);
    seen_bm |= digits_bm;
  }
  if (seen_bm == (1<<10) - 1) {
    return (i - 1) * n;
  }
  return -1;
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    ll n;
    cin >> n;
    ll ans = solve(n);
    if (ans == -1) {
      cout << "Case #" << ca << ": INSOMNIA" << endl;
    } else {
      cout << "Case #" << ca << ": " << ans << endl;
    }
  }
}
