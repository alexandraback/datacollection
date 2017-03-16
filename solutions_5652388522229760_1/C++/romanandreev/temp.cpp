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

void solve() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("INSOMNIA\n");
    return;
  }
  vector<bool> was(10);
  for (ll i = 1; ; i++) {
    ll x = i * n;
    while (x > 0) {
      was[x % 10] = true;
      x /= 10;
    }
    bool fin = true;
    for (int j = 0; j < 10; j++) {
      if (!was[j]) {
        fin = false;
      }
    }
    if (fin) {
      printf("%lld\n", i * n);
      return;
    }
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
