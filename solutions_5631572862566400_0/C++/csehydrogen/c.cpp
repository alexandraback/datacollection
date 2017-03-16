#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int const N = 1111;
int a[N], b[N], v[N], d[N];
bool cc[N];
vector<vector<int> > c;
void dfs(int here, int depth) {
  v[here] = depth;
  b[depth] = here;
  if (v[a[here]]) {
    if (!cc[here]) {
      vector<int> m;
      for (int i = v[a[here]]; i <= v[here]; ++i) {
        m.push_back(b[i]);
        cc[b[i]] = true;
      }
      c.push_back(m);
    }
    d[a[here]] = max(d[a[here]], v[a[here]]);
  } else {
    dfs(a[here], depth + 1);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      --a[i];
    }
    memset(cc, 0, sizeof(cc));
    memset(d, 0, sizeof(d));
    c.clear();
    for (int i = 0; i < n; ++i) {
      memset(v, 0, sizeof(v));
      dfs(i, 1);
    }
    int ans0 = 0, ans1 = 0;
    for (auto &cyc : c) {
      if (cyc.size() == 2) {
        ans0 += d[cyc[0]] + d[cyc[1]];
      } else {
        ans1 = max(ans1, (int)cyc.size());
      }
    }
    printf("Case #%d: %d\n", ti, max(ans0, ans1));
  }
  return 0;
}
