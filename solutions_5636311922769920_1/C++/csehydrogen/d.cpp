#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    int k, c, s;
    scanf("%d%d%d", &k, &c, &s);
    printf("Case #%d:", ti);
    int n = (k - 1) / c + 1;
    if (n > s) {
      printf(" IMPOSSIBLE\n");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      ll t = 0;
      for (int j = 0; j < c; ++j) {
        t *= k;
        t += min(i * c + j, k - 1);
      }
      printf(" %lld", t + 1);
    }
    printf("\n");
  }
  return 0;
}
