#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b, k;
int cnt[1005];

int main() {
  int T, cas = 0;
  scanf("%d", &T);
  while (T--) {
    memset(cnt, 0, sizeof(cnt));
    printf("Case #%d: ", ++cas);
    scanf("%d%d%d", &a, &b, &k);
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        ++cnt[i&j];
      }
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) ans += cnt[i];
    printf("%d\n", ans);
  }
  return 0;
}
