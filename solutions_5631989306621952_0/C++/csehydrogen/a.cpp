#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 1111;
char a[N], b[N];
int find_max(char *a, int e) {
  int m = a[0], mi = 0;
  for (int i = 1; i < e; ++i) {
    if (m <= a[i]) {
      m = a[i];
      mi = i;
    }
  }
  return mi;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    scanf("%s", a);
    int n = strlen(a), e = n, s = 0, be = n;
    while (e) {
      int m = find_max(a, e);
      b[s++] = a[m];
      memcpy(b + be - e + m + 1, a + m + 1, e - m - 1);
      be -= e - m - 1;
      e = m;
    }
    b[n] = 0;
    printf("Case #%d: %s\n", ti, b);
  }
  return 0;
}
