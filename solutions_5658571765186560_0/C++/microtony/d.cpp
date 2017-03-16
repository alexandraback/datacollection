#include <bits/stdc++.h>
using namespace std;
bool solve() {
  int x, r, c;
  scanf("%d %d %d", &x, &r, &c);
  if (x == 1) return false;
  if (x == 2) return r * c % 2;
  if (x == 3) {
    if (r == 1 || c == 1) return true;
    return r * c % 3;
  }
  if (x == 4) {
    if (r <= 2 || c <= 2) return true;
    return r * c % 4;
  }
  if (x == 5) {
    if (r <= 2 || c <= 2) return true;
    return r * c % 5;
  }
  if (x == 6) {
    if (r * c == 12) return true;
    if (r <= 2 || c <= 2) return true;
    return r * c % 6;
  }
  return true;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int caseno = 1; caseno <= t; caseno++) {
    printf("Case #%d: %s\n", caseno, solve() ? "RICHARD" : "GABRIEL");
  }
  return 0;
}

