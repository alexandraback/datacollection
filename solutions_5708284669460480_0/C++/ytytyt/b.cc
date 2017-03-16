#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long LL;

int T, ti;
int k, l, S;
string key, word;
int maxb, b;

void dfs(string &s, int d) {
  if (d == S) {
    // cout << s << endl;
    int i = 0, tt = 0;
    while ((i = s.find(word, i)) != string::npos) {
      i++;
      tt++;
    }
    maxb = max(maxb, tt);
    b += tt;
    // if (tt > 0)
      // cout << s << ' ' << tt << endl;
  } else {
    for (int i = 0; i < k; ++i) {
      s[d] = key[i];
      dfs(s, d+1);
    }
  }
}

int solve() {
  maxb = 0, b = 0;
  cin >> k >> l >> S;
  cin >> key >> word;
  string s(S, '.');
  dfs(s, 0);
  // cout << b << " " << maxb << endl;
  double ans = maxb - exp(log(b)-S*log(k));
  if (ans < 0)
    ans = 0;
  printf("Case #%d: %.8lf\n", ti, ans);
  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
