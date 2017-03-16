#include <cstdio>
#include <cstring>

using namespace std;

int n;
int cnt[2555];

int main() {
  int T;

  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    memset(cnt, 0, sizeof cnt);

    scanf("%d", &n);
    for (int i = 0; i < 2*n-1; ++i) {
      for (int j = 0, x; j < n; ++j)
        scanf("%d", &x), ++cnt[x];
    }

    printf("Case #%d:", t);

    for (int i = 0; i <= 2500; ++i)
      if (cnt[i] & 1)
        printf(" %d", i);
    puts("");
  }

  return 0;
}
