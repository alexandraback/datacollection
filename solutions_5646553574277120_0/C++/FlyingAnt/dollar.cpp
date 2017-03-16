#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int den[33], c, d, v;
int pos[33];

void go(int u, int val) {
  if (val <= v)
    pos[val] = 1;
  if (val > v || u >= d) return;
  go(u + 1, val);
  go(u + 1, val + den[u]);
}

int solve() {
  int ans = 0;
  while (true) {
    memset(pos, 0, sizeof(pos));
    go(0, 0);
    int i;
    for (i = 1; i <= v; i++)
      if (pos[i] == 0) {
        ans++;
        den[d++] = i;
        break;
      }
    if (i > v) break;
  }
  return ans;
}

int main() {
  int kases;
  scanf("%d", &kases);
  for (int kase = 1; kase <= kases; kase++) {
    scanf("%d %d %d", &c, &d, &v);
    for (int i = 0; i < d; i++) scanf("%d", den+i);
    printf("Case #%d: %d\n", kase, solve());
  }
  return 0;
}
