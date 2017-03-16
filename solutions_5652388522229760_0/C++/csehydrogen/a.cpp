#include <cstdio>
#include <cstring>
bool check(bool *v) {
  for (int i = 0; i < 10; ++i)
    if (!v[i]) return false;
  return true;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: ", ti);
    if (n == 0) {
      printf("INSOMNIA\n");
      continue;
    }
    bool v[10];
    memset(v, 0, sizeof(v));
    for (int i = 1; ; ++i) {
      int a = n * i;
      while (a) {
        v[a % 10] = true;
        a /= 10;
      }
      if (check(v)) {
        printf("%d\n", n * i);
        break;
      }
    }
  }
  return 0;
}
