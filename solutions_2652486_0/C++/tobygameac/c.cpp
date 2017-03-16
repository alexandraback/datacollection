#include <cstdio>
#include <set>
using std::set;

set<int> generate(int a, int b, int c) {
  set<int> s;
  s.insert(a);
  s.insert(b);
  s.insert(c);
  s.insert(a * b);
  s.insert(a * c);
  s.insert(b * c);
  s.insert(a * b * c);
  return s;
}

int main() {
  int T;
  scanf("%d", &T);
  puts("Case #1:");
  while (T--) {
    int R, N, M, K;
    scanf("%d%d%d%d", &R, &N, &M, &K);
    int min, max;
    if (N == 1) min = 2, max = M;
    if (N == 2) min = 22, max = M * 10 + M;
    if (N == 3) min = 222, max = M * 100 + M * 10 + M;
    while (R--) {
      int i, j;
      set<int> p;
      for (i = 0; i < K; i++) {
        scanf("%d", &j);
        if (j != 1) p.insert(j);
      }
      for (j = min; j <= max; j++) {
        if (j % 10 > M || j % 100 / 10 > M || j / 100 > M) continue;
        set<int> temp = p, s = generate(j / 100, j % 100 / 10, j % 10);
        for (set<int>::iterator it = s.begin(); it != s.end() && temp.size(); it++)
          temp.erase(*it);
        if (!temp.size()) break;
      }
      printf("%d\n", j);
    }
  }
  return 0;
}
