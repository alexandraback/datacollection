#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 15;

struct Node {
  vector<bool> v;
  int step;
};
vector<bool> a;
set<vector<bool>> vis;

int bfs() {
  vis.clear();
  queue<Node> que;
  que.push({a, 0});
  vis.insert(a);
  while (!que.empty()) {
    Node p = que.front(); que.pop();

    //for (auto i : p.v) { cout << i << ' '; } cout << "step:" << p.step << endl;

    if (all_of(p.v.begin(), p.v.end(), [](const bool & v) { return v; })) {
      return p.step;
    }
    p.step++;
    for (int i = 0; i < (int)p.v.size(); i++) {
      for (int j = 0; j <= i; j++) { p.v[j] = !p.v[j]; }
      reverse(p.v.begin(), p.v.begin() + i + 1);
      if (vis.find(p.v) == vis.end()) {
        que.push({p.v, p.step});
        vis.insert(p.v);
      }
      for (int j = 0; j <= i; j++) { p.v[j] = !p.v[j]; }
      reverse(p.v.begin(), p.v.begin() + i + 1);
    }
  }
  return -1;
}

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    a.clear();
    char s[N];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) { a.push_back(s[i] == '+'); }
    int ans = bfs();
    printf("Case #%d: %d\n", C, ans);
  }
}
