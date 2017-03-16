#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}

vector<ll> calc(ll k, ll c) {
  ll f = 0;
  vector<ll> res;
  for (int i = 0; i < (k + c - 1) / c; i++) {
    ll r = 0;
    for (int j = 0; j < c; j++) {
      r = r * k + f;
      f = min(f + 1, k - 1);
    }
    res.pb(r + 1);
  }
  return res;
}

void solve() {
  ll k, c;
  int s;
  cin >> k >> c >> s;
  vector<ll> ans = calc(k, c);
  if (sz(ans) > s) {
    printf("IMPOSSIBLE\n");
  } else {
    for (ll x : ans) {
      cout << x << " ";
    }
    cout<<endl;
  }
}

int main(){
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  int T;
  scanf("%d", &T);
  for (int ti = 1; ti <= T; ti++) {
    printf("Case #%d: ", ti);
    solve();
  }
  return 0;
}
