#include <cstdio>
#include <queue>
#include <utility>
#include <tuple>

const int MAX_S = 109;

int comp(int s, int l) {
  int r[2][MAX_S] = {};
  r[s][l] = 1;
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(s, l));
  while (!q.empty()) {
    std::tie(s, l) = q.front();
    if (s == 0 && l == 1) {
      return r[s][l]-1;
    }
    q.pop();
    for (int i = 1; i <= l; i += 2) {
      int nl = l;
      int ns = s == 0 ? 1 : 0;
      if (i != l)
        --nl;
      if (r[ns][nl] == 0) {
        r[ns][nl] = r[s][l]+1;
        q.push(std::make_pair(ns, nl));
      }
    }
  }
  return -1;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    char S[MAX_S];
    scanf("%s", S);
    int l = 1;
    for (int j = 1; S[j]; ++j) {
      if (S[j] != S[j-1])
        ++l;
    }
    printf("Case #%d: %d\n", i, comp(S[0] == '-', l));
  }
}