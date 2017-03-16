#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, c, s;

int main() {
  freopen("D-small-attempt0.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    scanf("%d%d%d", &k, &c, &s);
    printf("Case #%d:", C);
    for (int i = 1; i <= k; i++) {
      printf(" %d", i);
    }
    puts("");
  }
}
