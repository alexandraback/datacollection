
#include <bits/stdc++.h>

using namespace std;

bool win1(int r, int c) {
  return true;
}

bool win2(int r, int c) {
  return ((r * c) & 1) ? false : true;
}

bool win3(int r, int c) {
  if (c <= 4) {
    if (r == 2 && c == 3) return true;
    if (r == c && r == 3) return true;
    if (r == 3 && c == 4) return true;
    return false;
  }
  if (r == 1) return false;
  if ((r * c) % 3 == 0) return true;
  return false;
}

bool win4(int r, int c) {
  if (c <= 4) {
    if (r == 4 && c == 4) return true;
    if (r == 3 && c == 4) return true;
    return false;
  }
  if (r == 1 || r == 2) return false;
  if ((r * c) % 4 == 0) return true;
  return false;
}

// Surely I am joking.
bool win5(int r, int c) {
  if ((r * c) % 5 != 0) return false;
  if (r % 5 != 0) swap(r, c);
  if (r == 5) return c >= 12;
  if (r == 10) return c >= 6;
  if (r == 15) return c >= 4;
  if (r == 20) return c >= 3;
  return false;
}

bool win6(int r, int c) {
  return false;
}

bool win7(int r, int c) { // hole
  return false;
}

int main() {
  freopen("D-large.in", "r", stdin);
  freopen("D-large.out", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for (int tt = 1; tt <= tests; ++tt) {
    function<bool(int, int)> foo[8] = {nullptr, win1, win2, win3, win4, win5, win6, win7};
    int x, r, c;
    scanf("%d%d%d", &x, &r, &c);
    if (r > c) swap(r, c);
    printf("Case #%d: ", tt);
    if (x > 6) x = 7;
    if (foo[x](r, c)) puts("GABRIEL");
    else puts("RICHARD");
  }
  return 0;
}
