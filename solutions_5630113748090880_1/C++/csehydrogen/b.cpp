#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[2501], b[50];
int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 2 * n - 1; ++i)
      for (int j = 0; j < n; ++j) {
        int t;
        scanf("%d", &t);
        ++a[t];
      }
    int j = 0;
    for (int i = 1; i <= 2500; ++i)
      if (a[i] % 2)
        b[j++] = i;
    sort(b, b + n);
    printf("Case #%d:", ti);
    for (int i = 0; i < n; ++i)
      printf(" %d", b[i]);
    printf("\n");
  }
  return 0;
}
