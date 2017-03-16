/*
 * Code Jam Round 1A
 * File:   pBManageyourEnergy.cpp
 * Author: Andy Y.F. Huang
 * Created on April 26, 2013, 9:31 PM
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

namespace pBManageyourEnergy {
int val[11111];
int dp[12][11]; //pos, energy

void chmax(int& a, int b) {
  if (b > a) a = b;
}

void solve(int test_num) {
  int init, regen, len;
  scanf("%d %d %d", &init, &regen, &len);
  for (int i = 1; i <= len; i++)
    scanf("%d", val + i);
  memset(dp, 0xF0, sizeof (dp));
  dp[0][init] = 0;
  for (int i = 1; i <= len; i++)
    for (int e = 0; e <= init; e++)
      for (int j = 0; j <= e; j++)
        chmax(dp[i][min(init, e - j + regen)], dp[i - 1][e] + j * val[i]);
  int ans = *max_element(dp[len], dp[len] + 11);
  printf("Case #%d: %d\n", test_num, ans);
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
  pBManageyourEnergy::solve();
  return 0;
}

