#include <cstdio>
#include <vector>

typedef long long i64;

int main() {
  int tcase;
  scanf("%d", &tcase);
  for (int tid = 1; tid <= tcase; ++tid) {
    printf("Case #%d:", tid);
    int k, c, s;
    scanf("%d%d%d", &k, &c, &s);
    std::vector<i64> ans;
    if (c * s < k) {
      puts(" IMPOSSIBLE");
      continue;
    }
    i64 cur = 0;
    for (int i = 1; i <= k; ++i) {
      cur = cur * k + i - 1;
      if (i % c == 0) ans.push_back(cur + 1), cur = 0;
    }
    if (k % c) ans.push_back(cur + 1);
    for (int i = 0; i < ans.size(); ++i) printf(" %lld", ans[i]);
    puts("");
  }
  return 0;
}
