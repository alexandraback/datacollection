#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

const int L = 1024;

int check(int x, int y) {
  static char buf[L], buf1[L];
  sprintf(buf, "%d", x);
  sprintf(buf1, "%d", y);
  int dn = strlen(buf);
  for (int i = 0; i < dn; i++)
    buf[dn + i] = buf[i];
  buf[dn + dn] = 0;
  return strstr(buf, buf1) ? 1 : 0;
}

int solve(int x, int m) {
  static char buf[L], buf1[L];
  sprintf(buf, "%d", x);
  int dn = strlen(buf);
  for (int i = 0; i < dn; i++)
    buf[dn + i] = buf[i];
  buf[dn + dn] = 0;
  set<int> ss;
  for (int i = 1; i < dn; i++) {
    if (buf[i] == '0') continue;
    memcpy(buf1, buf + i, dn);
    buf1[dn] = 0;
    int y;
    sscanf(buf1, "%d", &y);
    if (x < y && y <= m)
      ss.insert(y);
  }
  return ss.size();
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    for (int x = n; x <= m; x++)
      ans += solve(x, m);
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
