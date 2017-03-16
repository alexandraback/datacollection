#include <cstdio>
#include <algorithm>
using namespace std;

void test() {
  int n, s, p, a;
  int res = 0;
  scanf("%d%d%d", &n, &s, &p);
  int minv = p + 2*max(0,p-1);
  int mins = p + 2*max(0,p-2);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a >= minv) res++;
    else if (s > 0 && a >= mins) {
      s--;
      res++;
    }
  }
  printf("%d\n", res);
}

main() {
  int t, cid = 1;
  scanf("%d", &t);
  while (t--) {
    printf("Case #%d: ", cid++);
    test();
  }
}
