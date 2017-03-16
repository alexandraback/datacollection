#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  cout << "Case #" << tc << ": ";
  ll k, c, s;
  cin >> k >> c >> s;
  if (s * c < k) cout << "IMPOSSIBLE" << endl;
  else {
    ll at = 0;
    ll left = k;
    while (left > 0 && at != k) {
      ll num = 0;
      rep(i,0,c) {
        at = min(at, k - 1);
        num = num * k + (at++);
      }
      cout << num + 1 << ' ';
      left -= c;
    }
    cout << endl;
  }
}

int main() {
  int N;
  cin >> N;
  rep(i,1,N+1) solve(i);
}
