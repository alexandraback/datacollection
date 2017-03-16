/*
 * Code Jam 2013 Round 1B
 * File:   pAOsmos.cpp
 * Author: Andy Y.F. Huang
 * Created on May 4, 2013, 12:01 PM
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

namespace pAOsmos {
int size[111];
int dp[122][122];
//max my size defeating i, using j opers

void solve(int test_num) {
  int me, len;
  cin >> me >> len;
  for (int i = 1; i <= len; i++)
    cin >> size[i];
  sort(size + 1, size + len + 1);
  memset(dp, 0, sizeof (dp));
  dp[0][0] = me;
  for (int i = 1; i <= len; i++) {
    for (int j = 0; j <= len; j++) {
      if (dp[i - 1][j] == 0)
        continue;
      dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j]); //delete
      for (int k = 0, t = dp[i - 1][j]; t <= 1000001; k++, t = 2 * t - 1) {
        if (t > size[i])
          dp[i][j + k] = max(dp[i][j + k], t + size[i]);
        if (t == 1)
          break;
      }
    }
  }
  for (int j = 0; j <= len; j++)
    if (dp[len][j] > 0) {
      printf("Case #%d: %d\n", test_num, j);
      fflush(stdout);
      return;
    }
  //assert(false);
}

void solve() {
  #ifdef AZN
  freopen("A-large.in", "r", stdin);
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
  pAOsmos::solve();
  return 0;
}

