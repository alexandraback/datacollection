#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
#define fr(a,b,c) for(int a = b; a < c; ++a)

int n;
int a[1100];

int pd[1100][1100];
int go(int x, int y) {
  if (x <= y) return 0;
  if (~pd[x][y]) return pd[x][y];
  int r = x;
  for (int i = y; i < x; ++i) {
    r = min(r, go(x-i, y) + go(i, y) + 1);
  }
  return pd[x][y] = r;
}

void doit() {
  scanf("%d", &n);
  fr(i,0,n) {
    scanf("%d", a+i);
  }
  int res = 1<<30;
  fr(i,1,1010) {
    int x = i;
    fr(j,0,n) x += go(a[j], i);
    res = min(res, x);
  }
  printf("%d\n", res);
}

int main() {
  memset(pd, -1, sizeof pd);
  int t; scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    printf("Case #%d: ", i);
    doit();
  }
  return 0;
}