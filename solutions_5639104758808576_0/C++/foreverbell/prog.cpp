
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1111;
int sMax;
char s[maxN];

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for (int tt = 1; tt <= tests; ++tt) {
    scanf("%d%s", &sMax, s);
    int stand = 0, result = 0;
    for (int i = 0; i <= sMax; ++i) {
      int is = s[i] - '0';
      if (is == 0) continue;
      if (i > stand) {
        result += i - stand;
        stand = i;  
      }
      stand += is;
    }
    printf("Case #%d: %d\n", tt, result);
  }
  return 0;
}
