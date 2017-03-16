#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;
const int maxn = 55;
LL p[maxn];
char ans[maxn][maxn];

int main() {
  freopen("/Users/wangchengrui/Desktop/B-large.in.txt", "r", stdin);
  freopen("/Users/wangchengrui/Desktop/B-large.out.txt", "w", stdout);
  int B, t, tt = 0;
  LL M;
  p[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    p[i] = (1LL << (i - 2));
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d%lld", &B, &M);
    memset(ans, '0', sizeof ans);
    printf("Case #%d: ", ++tt);
    if (M > (1LL << (B - 2))) {
      puts("IMPOSSIBLE");
    } else {
      puts("POSSIBLE");
      for (int i = 2; i < B; ++i) {
        for (int j = 1; j < i; ++j)
          ans[j][i] = '1';
      }
      for (int i = B - 1; i >= 1; --i) {
        if (M >= p[i]) {
          ans[i][B] = '1';
          M -= p[i];
        }
      }
      for (int i = 1; i <= B; ++i) {
        ans[i][B + 1] = 0;
        puts(ans[i] + 1);
      }
    }
  }
  return 0;
}
