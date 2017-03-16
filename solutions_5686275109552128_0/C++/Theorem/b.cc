#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int D;

int ticks[1001][1001] = { 0 };
int p[1000];

void solve(int CASE) {
  for (int i = 1; i <= 1000; i++)
    for (int j = 1; j <= 1000; j++)
      ticks[i][j] = (i+j-1)/j - 1;

  cin >> D;
  for (int i = 0; i < D; i++) {
    cin >> p[i];
  }

  int best = 10000;

  for (int i = 1; i <= 1000; i++) {
    int v = i;
    for (int j = 0; j < D; ++j) {
      v += ticks[p[j]][i];
    }

    best = min(best, v);
  }

  printf("Case #%d: %d\n", CASE, best);
}

int main() {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
