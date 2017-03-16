#include <bits/stdc++.h>

using namespace std;

const int maxN = 111;
int n, tests;
char pancake[maxN];

int solve() {
  n = strlen(pancake);
  int cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (pancake[i] != pancake[i - 1]) ++cnt;
  }
  if (pancake[n-1] == '-') ++cnt;
  return cnt;
}

int main() {
  freopen("B-large.in", "r", stdin);
  scanf("%d\n", &tests);
  for (int tt = 1; tt <= tests; ++tt) {
    gets(pancake);
    printf("Case #%d: %d\n", tt, solve());
  }
  return 0;
}

