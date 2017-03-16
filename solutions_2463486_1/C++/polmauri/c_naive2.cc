#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef long long ll;

const int N = 11000000;

ll acum[N];

bool palindrome(ll n) {
  stringstream ss;
  ss << n;
  string s = ss.str();
  int m = s.size();
  for (int i = 0; i < m; ++i)
    if (s[i] != s[m - 1 - i])
      return false;
  return true;
}

ll first_root(ll a) {
  ll e = 1, d = 100000000;
  while (e <= d) {
    ll m = (e + d)/2;
    if (a <= m*m) d = m - 1;
    else e = m + 1;
  }
  return d + 1;
}

ll last_root(ll b) {
  ll e = 1, d = 100000000;
  while (e <= d) {
    ll m = (e + d)/2;
    if (m*m <= b) e = m + 1;
    else d = m - 1;
  }
  return e - 1;
}

int main() {
  acum[0] = 0;
  for (ll i = 1; i < N; ++i) {
    acum[i] = acum[i - 1];
    if (palindrome(i) and palindrome(i*i)) ++acum[i];
  }
  
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cout << "Case #" << cas << ": ";
    ll a, b;
    cin >> a >> b;
    
    ll ra = first_root(a);
    ll rb = last_root(b);
    if (ra <= rb) cout << acum[rb] - acum[ra - 1] << endl;
    else cout << 0 << endl;
  }
}
