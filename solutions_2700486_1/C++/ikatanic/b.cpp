#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2010;

double C[MAXN][MAXN]; // (nCk)*(0.5)^n

double f(int n, int r, int a) { // na lijevu stranu tocno y, na desnu ostatak
  int b = n-a;
  if(b > r) return 0.0;
  if(b < r) return C[n][a];
  double ans = 0;
  for(int i = b; i <= n; ++i)
    ans += C[i-1][b-1]*0.5;
  return ans;
}

double solve(int n, int r, int x, int y) {
  if(n <= 0) return 0.0;
  if(r != x+y) return solve(n - (2*r+1), r+2, x, y);
  if(n >= 2*r+1) return 1.0;
  if(y == r) return 0.0;
  
  double bad = 0.0;
  for(int i = 0; i <= y; ++i)
    bad += f(n, r, i);
  return 1 - bad;
}

int main(void) {
  C[0][0] = 1;
  for(int i = 1; i < MAXN; ++i) {
    C[i][0] = C[i-1][0]*0.5;
    for(int j = 0; j < MAXN; ++j) {
      C[i][j] = (C[i-1][j] + C[i-1][j-1])*0.5;
    }
  }

  int t;
  scanf("%d", &t);
  for(int c = 1; c <= t; ++c) {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    if(x < 0) x = -x;
    printf("Case #%d: %lf\n", c, solve(n, 0, x, y));
  }
  return 0;
}
