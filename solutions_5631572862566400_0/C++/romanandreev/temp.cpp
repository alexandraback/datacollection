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
  vector<int> g(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &g[i]);
    g[i]--;
  }
  int ans = 0;
  int sum = 0;
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    vector<int> was(n);
    int x = i;
    int cnt = 0;
    while (1) {
      if (was[x]) {
        int mn = n;
        int len = cnt + 1 - was[x];
        for (int j = 0; j < len; j++) {
          mn = min(mn, x);
          x = g[x];
        }
        if (len == 2) {
          dp[x] = max(dp[x], cnt - 1);
        }
        ans = max(ans, len);
        break;
      }
      was[x] = ++cnt;
      x = g[x];
    }
  }
  for (auto x : dp) {
    sum += x;
  }
  cout << max(ans, sum) << endl;
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
