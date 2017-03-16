#include <stdio.h>

int main() {
  freopen("A-small.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  int test;
  scanf("%d", &test);
  for(int t=1; t<=test; ++t) {
    printf("Case #%d: ", t);
    int n, total = 0, more = 0;
    scanf("%d ", &n);
    for(int i=0; i<=n; ++i) {
      char c;
      scanf("%c", &c);
      if(total >= i) total += c-'0';
      else {
        more += i-total;
        total += i-total;
        total += c-'0';
      }
    }
    printf("%d\n", more);
  }
  return 0;
}