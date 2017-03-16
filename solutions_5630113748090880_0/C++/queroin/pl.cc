#include <bits/stdc++.h>

#define bug(xx) cerr << #xx << " = " << xx << endl; 

using namespace std;

#define FOR(a, b, i) for (ll i = a; i < b; ++i)

typedef long long int ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef long double ld;

void out(VI& v) {
  int n = v.size();
  FOR(0, n, i) {
    cout << v[i];
    if (i < n - 1) cout << ' ';
  }
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  FOR(1, t + 1, cas) {
    cout << "Case #" << cas << ": ";
    int n, x;
    cin >> n;
    set<int> s;
    FOR(0, 2 * n - 1, i) FOR(0, n, j) {
      cin >> x;
      if (s.count(x)) s.erase(x);
      else s.insert(x);
    }
    VI ans (n);
    int i = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) ans[i++] = *it;
    out(ans);
  }
}
