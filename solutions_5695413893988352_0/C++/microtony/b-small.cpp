#include <bits/stdc++.h>
using namespace std;
char s[20], t[20];
vector<long long> a, b;
void gen(char* s, vector<long long>& v, int x, long long y) {
  if (!s[x]) {
    v.push_back(y);
    return ;
  }
  if (s[x] == '?') {
    for (int i = 0; i <= 9; i++) {
      gen(s, v, x + 1, y * 10 + i);
    }
  } else {
    gen(s, v, x + 1, y * 10 + (s[x] - '0'));
  }
}
void solve() {
  scanf("%s %s", s, t);
  int n = strlen(s);
  a.clear();
  b.clear();
  gen(s, a, 0, 0);
  gen(t, b, 0, 0);
  long long d = 1111111111111111111LL;
  long long dx, dy;
  for (long long x : a) {
    for (long long y : b) {
      if (abs(x - y) < d) {
        d = abs(x - y);
        dx = x;
        dy = y;
      } else if (abs(x - y) == d) {
        if (x < dx) {
          dx = x;
          dy = y;
        } else if (x == dx) {
          if (y < dy) {
            dy = y;
          }
        }
      }
    }
  }
  printf("%.*lld %.*lld", n, dx, n, dy);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
    printf("\n");
  }
  return 0;
}
