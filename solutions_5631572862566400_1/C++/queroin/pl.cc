#include <bits/stdc++.h>

#define bug(xx) cerr << #xx << " = " << xx << endl; 

using namespace std;

#define FOR(a, b, i) for (ll i = a; i < b; ++i)

typedef long long int ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef long double ld;
typedef pair<int, int> ii;

VVI trans;
VB vist;
int n;

int dfs(int u) {
  vist[u] = true;
  int sup = 0;
  FOR(0, trans[u].size(), i) if (not vist[trans[u][i]]) sup = max(sup, dfs(trans[u][i]));
  return 1 + sup;
}

int main() {
  int t;
  cin >> t;
  FOR(1, t + 1, cas) {
    cout << "Case #" << cas << ": ";
    cin >> n;
    VI next (n);
    FOR(0, n, i) cin >> next[i];
    FOR(0, n, i) --next[i];
    int ans = 0;
    FOR(0, n, i) {//mira si te cicles
      int pos = i;
      VB vist (n, false);
      int cnt = 0;
      while (not vist[pos]) {
	vist[pos] = true;
	pos = next[pos];
	++cnt;
      }
      if (pos == i) ans = max(ans, cnt);
    }
    set<ii> pairs;
    FOR(0, n, i) if (i == next[next[i]] and i < next[i]) pairs.insert(ii(i, next[i]));
    trans = VVI (n);
    FOR(0, n, i) trans[next[i]].push_back(i);
    int sum = 0;
    for (set<ii>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
      int u = it->first, v = it->second;
      vist = VB (n, false);
      vist[v] = true;
      sum += dfs(u);
      vist = VB (n, false);
      vist[u] = true;
      sum += dfs(v);
    }
    cout << max(sum, ans) << '\n';
  }
}
