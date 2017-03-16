#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXN = 123456;

bool can[MAXN];

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    int ans = 0;
    int C, D, V;
    scanf("%d %d %d", &C, &D, &V);
    memset(can, 0, sizeof(can));
    for (int i = 0; i < D; ++i) {
      int x;
      scanf("%d", &x);
      can[x] = 1;
    }
    int need = 0;
    for (int i = 1; i <= V; ++i) {
      if (!can[i]) {
        ++need;
        // cout << i << endl;
        can[i] = true;
      }
      int lim = 2 * i - 1;
      for (int j = i + 1; j <= lim; ++j) {
        if (can[j]) {
          lim = lim + j;
        }
      }
      i = lim;
    }
    ans = need;
    printf("Case #%d: %d\n", T, ans);
  }
}