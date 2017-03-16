#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int tests, K, C, S;

LL encode(vector<int> v) {
  LL ret = 0;
  for (int x : v) {
    ret = ret * K + (x - 1);
  }
  return ret + 1;
}

vector<LL> solve() {
  scanf("%d%d%d", &K, &C, &S);
  vector<LL> r;
  int bound = K / C;
  if (K % C != 0) bound += 1;
  if (S < bound) return r;
  for (int i = 1; i <= K; i += C) {
    vector<int> tmp;
    for (int j = i; j < i + C; ++j) {
      tmp.push_back(min(j, K));
    }
    r.push_back(encode(tmp));
  }
  return r;
}

int main() {
  freopen("D-large.in", "r", stdin);
  scanf("%d", &tests);
  for (int tt = 1; tt <= tests; ++tt) {
    printf("Case #%d: ", tt);
    auto v = solve();
    if (v.empty()) puts("IMPOSSIBLE");
    else {
      for (int i = 0; i < v.size(); ++i) {
        printf("%lld%c", v[i], i+1==v.size() ? '\n' : ' ');
      }
    }
  }
  return 0;
}
