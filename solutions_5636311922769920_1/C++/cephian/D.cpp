#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ll;

ll k,c,s;

ll pw(ll a, ll b) {
  if(b == 0) return a;
  if(b&1) return a*pw(a,b-1);
  ll t = pw(a,b/2);
  return t*t;
}

ll check(ll pos, int tile, int depth) {
  if(depth >= c) return pos;
  if(tile < k-1)
    ++tile;
  return check(k*pos+tile,tile,depth+1);
}

vector<ll> checks;

int main() {
  // freopen("d.in","r",stdin);
  freopen("d.txt","w",stdout);
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    cin >> k >> c >> s;
    cout << "Case #" << t << ": ";
    checks.clear();
    for(int i = 0; i < k; i += c) {
      checks.push_back(check(i,i,1));
    }
    if(checks.size() > s) cout << "IMPOSSIBLE\n";
    else {
      for(int i = 0; i < checks.size(); ++i) {
        cout << checks[i]+1;
        if(i != checks.size()-1) cout << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}