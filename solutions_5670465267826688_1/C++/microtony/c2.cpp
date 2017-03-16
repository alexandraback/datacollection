#include <bits/stdc++.h>
using namespace std;
char s[160005];
int x[160005];
int y[160005];
int m[8][8] = {
  {0, 1, 2, 3, 4, 5, 6, 7},
  {1, 4, 3, 6, 5, 0, 7, 2},
  {2, 7, 4, 1, 6, 3, 0, 5},
  {3, 2, 5, 4, 7, 6, 1, 0},
  {4, 5, 6, 7, 0, 1, 2, 3},
  {5, 0, 7, 2, 1, 4, 3, 6},
  {6, 3, 0, 5, 2, 7, 4, 1},
  {7, 6, 1, 0, 3, 2, 5, 4}
};
bool solve() {
  long long l, r;
  scanf("%lld %lld %s", &l, &r, s);
  if (r > 12) {
    r = 12 + r % 4;
  }
  for (int i = 0; i < l; i++) {
    if (s[i] == '1') {
      x[i] = 0;
    }
    if (s[i] == 'i') {
      x[i] = 1;
    }
    if (s[i] == 'j') {
      x[i] = 2;
    }
    if (s[i] == 'k') {
      x[i] = 3;
    }
  }
  for (int i = 0; i < l * r; i++) {
    y[i + 1] = m[y[i]][x[i % l]];
  }
  if (y[l * r] != 4) {
    return false;
  }
  for (int i = 1; i < l * r; i++) {
    if (y[i] != 1) continue;
    for (int j = i + 1; j < l * r; j++) {
      if (y[j] == 3) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int caseno = 1; caseno <= t; caseno++) {
    printf("Case #%d: %s\n", caseno, solve() ? "YES" : "NO");
  }
  return 0;
}

