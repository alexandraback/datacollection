#include <bits/stdc++.h>
using namespace std;

int t, x, r, c, a, dmin, dmax;
int ca;
void pr() { printf("Case #%d: RICHARD\n", ca); }
void pg() { printf("Case #%d: GABRIEL\n", ca); }

int main() {
  scanf("%d", &t);
  for (ca=1; ca<=t; ca++) {
    scanf("%d %d %d", &x, &r, &c);

    a = r * c;
    dmin = min(r, c);
    dmax = max(r, c);
    if (a % x != 0 || a < x) {
        pr(); continue;
    }
    switch (x) {
      case 1:
        pg(); break;
      case 2:
        if (a % 2 == 0) pg(); else pr();
        break;
      case 3:
        if (dmin > 1 && dmax >= 3) pg();
        else pr();
        break;
      case 4:
        if (dmin <= 2 || dmax < 4) pr();
        else pg();
        break;
      case 5:
        if (dmin <= 3 || dmax < 5) pr();
        else pg();
        break;
      case 6:
        if (dmin <= 3 || dmax < 6) pr();
        else pg();
        break;
      default:
        pr();
    }
  }
}
