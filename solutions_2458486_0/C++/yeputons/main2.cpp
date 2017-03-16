#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

void solve() {
  int k, n;
  scanf("%d%d", &k, &n);

  vi start(k);
  for (int i = 0; i < k; i++)
    scanf("%d", &start[i]);

  vi need(n);
  vvi cs(n);
  for (int i = 0; i < n; i++) {
    int cnt;
    scanf("%d%d", &need[i], &cnt);
    cs[i].resize(cnt);
    for (int i2 = 0; i2 < cnt; i2++)
      scanf("%d", &cs[i][i2]);
  }

  vvi ans(1 << n);
  vb can(1 << n);
  can[0] = true;
  for (int msk = 0; msk < (1 << n); msk++) if (can[msk]) {
    vi cur = start;
    for (int i = 0; i < n; i++) if (msk & (1 << i))
      cur.insert(cur.begin(), cs[i].begin(), cs[i].end());
    for (int i = 0; i < n; i++) if (msk & (1 << i)) {
      assert(find(cur.begin(), cur.end(), need[i]) != cur.end());
      cur.erase(find(cur.begin(), cur.end(), need[i]));
    }

    for (int i = 0; i < n; i++) if (!(msk & (1 << i))) {
      int nmsk = msk | (1 << i);
      if (find(cur.begin(), cur.end(), need[i]) == cur.end())
        continue;

      vi cans = ans[msk];
      cans.pb(i);
      if (!can[nmsk]) {
        can[nmsk] = true;
        ans[nmsk] = cans;
      } else {
        ans[nmsk] = min(ans[nmsk], cans);
      }
    }
  }
  if (!can.back()) {
    printf("IMPOSSIBLE\n");
    return;
  }
  vi res = ans.back();
  for (int i = 0; i < sz(res); i++)
    printf("%d%c", res[i] + 1, "\n "[i + 1 < sz(res)]);
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "std";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Catched exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
