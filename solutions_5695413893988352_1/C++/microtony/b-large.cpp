#include <bits/stdc++.h>
using namespace std;
char s[25], t[25];
struct d {
  long long diff;
  string s, t;
  bool operator<(const d& o) const {
    if (diff != o.diff) return diff < o.diff;
    if (diff < 0) {
      if (s != o.s) return s > o.s;
      return t > o.t;
    } else {
      if (s != o.s) return s < o.s;
      return t < o.t;
    }
  }
};
vector<d> v[25], w[25];
void solve() {
  scanf("%s %s", s + 1, t + 1);
  int n = strlen(s + 1);
  w[0].clear();
  w[0].push_back({0, "", ""});
  d zero = {0, "", ""};
  for (int i = 1; i <= n; i++) {
    v[i].clear();
    w[i].clear();
    for (d& x : w[i - 1]) {
      for (int j = (s[i] == '?' ? 0 : (s[i] - '0')); j <= (s[i] == '?' ? 9 : (s[i] - '0')); j++) {
        for (int k = (t[i] == '?' ? 0 : (t[i] - '0')); k <= (t[i] == '?' ? 9 : (t[i] - '0')); k++) {
          v[i].push_back({x.diff * 10 + j - k, x.s + (char)('0' + j), x.t + (char)('0' + k)});
        }
      }
    }
    sort(v[i].begin(), v[i].end());
    auto it = lower_bound(v[i].begin(), v[i].end(), zero);
    //printf("%d %d\n", v[i].size(), it - v[i].begin());
    if (it == v[i].end()) it--;
    w[i].push_back(*(it));
    if (it->diff == 0) {
      auto it2 = it + 1;
      while (it2 != v[i].end() && it2->diff == 0) {
        it2++;
      }
      if (it2 != v[i].end()) {
        w[i].push_back(*it2);
      }
    }
    if (it != v[i].begin()) {
      w[i].push_back(*(it - 1));
    }
    
  }
  auto it = lower_bound(w[n].begin(), w[n].end(), zero);
  if (it == w[n].end()) it--;
  long long bestdiff = abs(it->diff);
  string bests = it->s, bestt = it->t;
  if (it != w[n].begin()) {
    it--;
    if (abs(it->diff) < bestdiff) {
      bests = it->s;
      bestt = it->t;
    } else if (abs(it->diff) == bestdiff) {
      if (it->s < bests) {
        bests = it->s;
        bestt = it->t;
      } else if (it->s == bests && it->t < bestt) {
        bests = it->s;
        bestt = it->t;
      }
    }
  }
  printf("%s %s", bests.c_str(), bestt.c_str());
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
    printf("\n");
  }
  return 0;
}
