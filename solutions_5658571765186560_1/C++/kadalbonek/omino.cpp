#include <bits/stdc++.h>

/**
 * Hayo mau liat apa
 * Asu kon
 */

using namespace std;

int ans[25][25][25];

bool get(int x, int r, int c) {
  // r <= c
  if(x >= 7) return 0;
  if(r * c % x) return 0;
  if(x <= r && x <= c) return 1;
  return ans[x][r][c];
}

int main() {
  for(int x = 1; x <= 6; x++) {
    for(int r = 1; r <= 6; r++) {
      for(int c = r; c <= 6; c++) {
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
    if(r > c) swap(r, c);
    printf("Case #%d: ", tt);
    puts(get(x, r, c)? "GABRIEL" : "RICHARD");
  }
  
  return 0;
}
