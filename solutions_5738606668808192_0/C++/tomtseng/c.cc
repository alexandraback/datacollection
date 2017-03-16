#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, J;

ll conv(ll n, ll base) {
  ll num = 1;

  for (int i = 0; i < N-2; i++) {
    num = num*base + (n&1);
    n >>= 1;
  }

  num = num*base + 1;

  return num;
}

vector<ll> divs;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll T;
  cin >> T >> N >> J;

  cout << "Case #1:\n";

  ll n = 0;

  while(J) {
    divs.clear();
    bool success = true;

    for (int b = 2; b <= 10; b++) {

      ll c = conv(n, b);

      if (c % 2 == 0) {
        divs.push_back(2);
        continue;
      }

      ll maxdiv = ll(sqrt(c));
      bool bs = false;

      for (ll i = 3; i <= maxdiv; i += 2) {
        if (c % i == 0) {
          divs.push_back(i);
          bs = true;
          break;
        }
      }

      if (!bs) {
        success = false;
        break;
      }
    }

    if (success) {
      J--;

      cout << conv(n, 10) << " ";

      for (int i = 0; i < 9; i++) {
        cout << divs[i] << " ";
      }
      cout << "\n";
    }

    n++;
  }


  return 0;
}
