#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int T;
const double eps = 1e-8;
int R, C, M;
char dp[51][51][2501];
vector<int> lens;

void f(int row, int cur, int sum, int area) {
  if (sum > area)
    return;
  if (row == R)
    return;
  if (sum == area)
    dp[row][cur][sum] = 1;
  if (dp[row][cur][sum] != -1)
    return;
  dp[row][cur][sum] = 1;
  for (int x = cur; x > 1; --x)
    f(row + 1, x, sum + x, area);
}

void restore(int row, int cur, int sum) {
  if (row == 0)
    return lens.push_back(cur);
  for (int prv = cur; prv <= C; ++prv)
    if (dp[row - 1][prv][sum - cur] != -1)
      restore(row - 1, prv, sum - cur);
  lens.push_back(cur);
}

void solve() {
  for (int i = 2; i <= C; ++i) {
    dp[0][i][i] = true;
    f(1, i, i << 1, R * C - M);
  }
  for (int row = 1; row < R; ++row)
    for (int cur = 2; cur <= C; ++cur)
      if (dp[row][cur][R * C - M] != -1)
	return restore(row, cur, R * C - M);
}

int main() {
  freopen("C-small-attempt1.in", "r", stdin);
  freopen("C-small-attempt1.out", "w", stdout);
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    lens.clear();
    memset(dp, 0xff, sizeof dp);    
    cin >> R >> C >> M;
    printf("Case #%d:\n", i);
    fflush(stdout);
    if (R == 1 || C == 1) {
      M = R * C - 1 - M;
      for (int j = 0; j < R; ++j) {
	for (int k = 0; k < C; ++k) {
	  if (j == 0 && k == 0)
	    putchar('c');
	  else if (M)
	    putchar('.'), --M;
	  else putchar('*');
	}
	putchar('\n');
      }
    }
    else if (R * C - M == 1) {
      for (int j = 0; j < R; ++j) {
	for (int k = 0; k < C; ++k) {
	  if (j == 0 && k == 0)
	    putchar('c');
	  else putchar('*');      
	}
	putchar('\n');
      }
    }
    else {
      solve();
      if (lens.size()) {
	for (int j = 0; j < R; ++j) {
	  for (int k = 0; k < C; ++k) {
	    if (j == 0 && k == 0)
	      putchar('c');
	    else if (j < lens.size() && k < lens[j])
	      putchar('.');
	    else putchar('*');
	  }
	  putchar('\n');
	}
      }
      else puts("Impossible");
    }
  }
  return 0;
}
