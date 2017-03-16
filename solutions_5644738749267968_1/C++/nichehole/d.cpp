#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[1005], b[1005];

int main() {
  int T, cas = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%*d.%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%*d.%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);
    //for (int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");
    //for (int i = 0; i < n; ++i) printf("%d ", b[i]); puts("");
    int A = 0, B = 0;
    for (int i = 0; i + A < n; ++i) {
      while (a[i] > b[i + A] && i + A < n) ++A;
    }
    for (B = 0; B < n; ++B) {
      bool f = 1;
      for (int i = 0; i + B < n && f; ++i) {
        f = a[i + B] > b[i];
      }
      if (f) break;
    }
    printf("Case #%d: ", ++cas);
    printf("%d %d\n", n - B, A);
  }
  return 0;
}
