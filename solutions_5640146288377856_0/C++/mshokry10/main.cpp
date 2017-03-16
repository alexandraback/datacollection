#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
  int T, tst = 1;
  scanf("%d", &T);
  while (T--) {
    int r, c, w;
    scanf("%d %d %d", &r, &c, &w);
    printf("Case #%d: %d\n", tst, (c + w - 1) / w + w - 1);
    ++tst;
  }
}