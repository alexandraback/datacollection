#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

char kb[111], w[111], g[111];
int f[26], nk, nw, s;
int mx = 0;
double ans = 0;

void brute(int u, double pr) {
  if (u >= s) {
    int cnt = 0;
    for (int i = 0; i + nw <= s; i++) {
      bool match = true;
      for (int j = 0; j < nw; j++)
        match = match && (w[j] == g[i + j]);
      if (match) cnt++;
    }
    if (mx < cnt) mx = cnt;
    ans += pr * cnt;
    return;
  }

  for (int i = 0; i < 26; i++)
    if (f[i]) {
      g[u] = 'A' + i;
      brute(u + 1, pr * (1. * f[i]) / (1. * nk));
    }
}

double solve() {
  memset(f, 0, 26 * sizeof(int));
  for (int i = 0; i < nk; i++) f[kb[i] - 'A']++;
  mx = 0;
  ans = 0;
  brute(0, 1);
  return mx - ans;
}

int main() {
  int kases;
  scanf("%d", &kases);
  for (int kase = 1; kase <= kases; kase++) {
    scanf("%d %d %d\n", &nk, &nw, &s);
    gets(kb);
    gets(w);
    printf("Case #%d: %.6lf\n", kase, solve());
  }
  return 0;
}
