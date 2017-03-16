
#include <bits/stdc++.h>

using namespace std;

bool win1(int r, int c) {
  return true;
}

bool win2(int r, int c) {
  return ((r * c) & 1) ? false : true;
}

bool win3(int r, int c) {
  if (r > c) swap(r, c);
  if (r == 2 && c == 3) return true;
  if (r == c && r == 3) return true;
  if (r == 3 && c == 4) return true;
  return false;
}

bool win4(int r, int c) {
  if (r > c) swap(r, c);
  if (r == 4 && c == 4) return true;
  if (r == 3 && c == 4) return true;
  return false;
}

int main() {
  freopen("D-small-attempt0.in", "r", stdin);
  freopen("D-small-attempt0.out", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for (int tt = 1; tt <= tests; ++tt) {
    function<bool(int, int)> foo[5] = {win1, win1, win2, win3, win4};
    int x, r, c;
    scanf("%d%d%d", &x, &r, &c);
    printf("Case #%d: ", tt);
    if (foo[x](r, c)) puts("GABRIEL");
    else puts("RICHARD");
  }
  return 0;
}
