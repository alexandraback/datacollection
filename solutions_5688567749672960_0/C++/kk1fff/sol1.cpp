#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll pl(ll n, ll p) {
  ll s = 1;
  while (p--) {
    s *= n;
  }
  return s;
}

int reverse(ll i) {
  ll r = 0;
  while (i) {
    r = r * 10 + i % 10;
    i /= 10;
  }
  return r;
}

int digits(ll i) {
  int d = 0;
  while (i) {
    d++;
    i /= 10;
  }
  return d;
}

ll todigit(int i) {
  if (i == 1) return 1;
  if (i == 2) return 10;
  return todigit(i-1) + 10 + (pl(10, i-2) - 1);
}

void run(int t) {
  ll target;
  cin >> target;
  int d = digits(target);
  if (d == 1) {
    cout << "Case #" << t << ": " << target << endl;
    return;
  }
  
  ll cur = todigit(d);
  ll num = pl(10LL, (ll)d-1);

  ll msd = reverse(target) % pl(10LL, (ll)d/2);
  ll lsd = target % pl(10LL, (ll)(d - (d/2)));
  // cout << msd << ", " << lsd << endl;
  if (lsd != 0) {
    cur += msd;
    num += msd;
  } else {
    cur += (msd - 1);
    num += (msd - 1);
  }

  cur += min(target - reverse(num) + 1,
             target - num);
  cout << "Case #" << t << ": " << cur << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    run(i);
  }
}
