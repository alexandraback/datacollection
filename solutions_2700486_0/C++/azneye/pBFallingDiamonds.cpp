/*
 * Code Jam Round 1B 2013
 * File:   pBFallingDiamonds.cpp
 * Author: Andy Y.F. Huang
 * Created on May 4, 2013, 12:44 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace pBFallingDiamonds {
double dp[22][22][22];
//blocks, cnt left, cnt right

void print(double x) {
  printf("%.7lf\n", x);
}

double go(int cnt, int diag, int total, int x, int y) {
  if (abs(x) + y < diag) return 1; //lower diag
  if (abs(x) + y > diag) return 0; //high diag
  if (cnt == total) return 1; //middle diamond
  if (x == 0) return 0; //middle diamond but not dropped yet
  int half = total >> 1;
  memset(dp, 0, sizeof (dp));
  dp[0][0][0] = 1;
  for (int i = 0; i < total; i++) {//number of blocks
    for (int a = 0; a <= i; a++) {
      for (int b = 0; b <= i; b++) {
        if (a + b != i)
          continue;
        if (a + 1 <= half && b + 1 <= half) {
          dp[i + 1][a + 1][b] += 0.5 * dp[i][a][b];
          dp[i + 1][a][b + 1] += 0.5 * dp[i][a][b];
        }
        else if (a + 1 <= half)
          dp[i + 1][a + 1][b] += dp[i][a][b];
        else if (b + 1 <= half)
          dp[i + 1][a][b + 1] += dp[i][a][b];
      }
    }
  }
  int a = 0, b = 0;
  if (x < 0) a = y + 1;
  else b = y + 1;
  double res = 0.0;
  for (int l = a; l <= half; l++)
    for (int r = b; r <= half; r++)
      res += dp[cnt][l][r];
  return res;
}

void solve(int test_num) {
  //1, 5, 9, 17
  int len, x, y;
  scanf("%d %d %d", &len, &x, &y);
  printf("Case #%d: ", test_num);
  if (len == 1)
    print(x == 0 && y == 0 ? 1.0 : 0.0);
  else if (len <= 6)
    print(go(len - 1, 2, 5, x, y));
  else if (len <= 15)
    print(go(len - 6, 4, 9, x, y));
  else
    print(go(len - 15, 6, 17, x, y));
}

void solve() {
  #ifdef AZN
  freopen("inputB.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  pBFallingDiamonds::solve();
  return 0;
}

