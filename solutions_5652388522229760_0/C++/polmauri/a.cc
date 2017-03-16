#include <iostream>
using namespace std;

typedef long long ll;

int digits(ll n) {
  int mask = 0;
  while (n >= 10) {
    mask |= 1<<(n%10);
    n /= 10;
  }
  mask |= 1<<n;
  return mask;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cout << "Case #" << cas << ": ";
    ll n;
    cin >> n;
    if (n == 0) {
      cout << "INSOMNIA" << endl;
      continue;
    }
    ll res = 0;
    int mask = 0;
    while (mask != (1<<10) - 1) {
      res += n;
      mask |= digits(res);
    }
    cout << res << endl;
  }
}
