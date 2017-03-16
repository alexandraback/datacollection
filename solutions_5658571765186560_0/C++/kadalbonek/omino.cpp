#include <bits/stdc++.h>

/**
 * Hayo mau liat apa
 * Asu kon
 */

using namespace std;

int ans[25][25][25];

int main() {
  for(int x = 1; x <= 4; x++) {
    for(int r = 1; r <= 4; r++) {
      for(int c = r; c <= 4; c++) {
        // r <= c
        if(r * c % x) continue;
        if(r >= x - 1 && c >= x) {
          ans[x][r][c] = ans[x][c][r] = 1;
        }
      }
    }
  }

  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int x, r, c;
    scanf("%d %d %d", &x, &r, &c);
    printf("Case #%d: ", tt);
    puts(ans[x][r][c]? "GABRIEL" : "RICHARD");
  }
  
  return 0;
}
