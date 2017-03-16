#include <bits/stdc++.h>

#define bug(xx) cerr << #xx << " = " << xx << endl; 

using namespace std;

#define FOR(a, b, i) for (ll i = a; i < b; ++i)

typedef long long int ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef long double ld;

string optim(string s) {
  int n = s.size();
  string r = "";
  FOR(0, n, i) r = max(r + s[i], s[i] + r);
  return r;
}

int main() {
  int t;
  cin >> t;
  FOR(1, t + 1, cas) {
    cout << "Case #" << cas << ": ";
    string s;
    cin >> s;
    cout << optim(s) << '\n';
  }
}
