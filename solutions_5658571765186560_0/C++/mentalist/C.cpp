#include <stdio.h>

int ans[10][4] = {
  { 1, 0, 0, 0 },
  { 1, 1, 0, 0 },
  { 1, 0, 0, 0 },
  { 1, 1, 0, 0 },
  { 1, 1, 0, 0 },
  { 1, 1, 1, 0 },
  { 1, 1, 0, 0 },
  { 1, 0, 1, 0 },
  { 1, 1, 1, 1 },
  { 1, 1, 0, 1 }
};

int h[4] = { 0, 4, 7, 9 };

int main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int test;
  scanf("%d", &test); 
  for(int t=1; t<=test; ++t) {
    int x, r, c, tp;
    scanf("%d %d %d", &x, &r, &c);
    if(r > c) {
      tp = r;
      r = c;
      c = tp;
    }
    x--;
    r--;
    c--;
    int idx = h[r] + c-r;
    printf("Case #%d: %s\n", t, ans[idx][x] ? "GABRIEL" : "RICHARD");
  }
  return 0;
}
