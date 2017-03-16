#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<long long> VI;
typedef vector<VI> VVI;

int solve(const VVI &sons, int st, int fr) {
  int ans = 1, pow = 1;
  queue<pair<int, int>> q;
  q.push(pair<int, int>(st, pow));
  while (q.size() > 0) {
    int c = q.front().first;
    int p = q.front().second;
    if (p > ans) ans = p;
    q.pop();
    for (int i = 0; i < sons[c].size(); ++i) {
      if (sons[c][i] != fr)
        q.push(pair<int, int>(sons[c][i], p+1));
    }
  }
  return ans;
}

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  freopen("C-small-attempt2.in", "rt", stdin);
  //freopen("C-large.in", "rt", stdin);
  freopen("output2.txt", "w", stdout);
#endif

  int line_num;
  cin >> line_num;
  for (int line = 0; line < line_num; ++line) {
    int k; cin >> k;
    VI bbf(k), vis(k);
    VVI sons(k);
    for (int i = 0; i < k; ++i) {
      int x;
      cin >> x;
      bbf[i] = x - 1;
      sons[x - 1].push_back(i);
    }
    int a = 1;
    int cur = 0;
    while (cur < k) {
      int n = 0;
      map<int, int> count;
      while (vis[cur] == 0) {
        vis[cur] = 1;
        count[cur] = n;
        ++n;
        cur = bbf[cur];
      }
      if (count.size() > 0 && count.find(cur) != count.end()) {
        n = count.size() - count[cur];
      }
      if (n > a) a = n;
      ++cur;
    }
    int alt = 0;
    for (int i = 0; i < k; ++i) {
      if (bbf[bbf[i]] == i) {
        alt += solve(sons, i, bbf[i]);
      }
    }
    if (a < alt) {
      a = alt;
      //cout << "alt";
    }

    printf("Case #%d: %d\n", line+1, a);
  }

  return 0;
}
