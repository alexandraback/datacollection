#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int maxn = 2500 + 10;
int num[maxn];

int main() {
  // freopen("B-small-attempt0", "r", stdin);
  // freopen("B-small.out", "w", stdout);
  
  int TextN, n;
  scanf("%d", &TextN);
  for (int TT = 1; TT <= TextN; TT++) {
    printf("Case #%d:", TT);

    int x;
    memset(num, 0, sizeof(num));

    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 1; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &x);
        num[x]++;
      }
    }

    for (int i = 1; i < maxn; i++) {
      if (num[i] % 2 == 1) printf(" %d", i);
    }
    printf("\n");
  }

  return 0;
}