#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i, a, b) for (int _n(b), i(a); i < _n; i++)
#define rep(i, n) FOR(i, 0, n)
#define CL(a, v) memset((a), (v), sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;

/*** TEMPLATE CODE ENDS HERE */

vector<string> dic = {"ZERO", "ONE", "TWO",   "THREE", "FOUR",
                      "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void solve() {
  string s;
  cin >> s;
  VI p(dic.size());
  rep(i, (int)p.size()) p[i] = i;
  do {
    int cnt[26] = {0};
    for (auto c : s) cnt[c - 'A']++;
    VI ans;
    int digit = 0;
    rep(k, (int)dic.size()) {
      string w = dic[p[k]];
      int cnt2[26] = {0};
      for (char c : w) cnt2[c - 'A']++;
      for (;;) {
        bool can = true;
        rep(i, 26) can &= cnt2[i] <= cnt[i];
        if (can) {
          for (char c : w) cnt[c - 'A'] -= 1;
          ans.pb(p[k]);
        } else {
          break;
        }
      }
      ++digit;
    }
    bool ok = true;
    rep(i, 26) ok &= cnt[i] == 0;
    if (ok) {
      SORT(ans);
      for (int x : ans) cout << x;
      return;
    }
  } while (next_permutation(all(p)));
}

int main() {
#ifdef LOCAL_HOST
  freopen("A-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cout.sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  FOR(tt, 1, T + 1) {
    cout << "Case #" << tt << ": ";
    solve();
    cout << endl;
  }

  return 0;
}
