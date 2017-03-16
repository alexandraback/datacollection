/*
 * 
 * File:   pBCookieClickerAlpha.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Apr 11, 2014, 7:11:28 PM
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

using namespace std;

namespace pBCookieClickerAlpha {
double C, F, X;

void solve(int test_num) {
  cin >> C >> F >> X;
  double res = X / 2.0, sum = 0;
  for (int f = 0; sum < res; f++) {
    sum += C / (2 + f * F);
    res = min(res, sum + X / (2 + (f + 1) * F));
  }
  printf("Case #%d: %.7lf\n", test_num, res);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
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
  pBCookieClickerAlpha::solve();
  return 0;
}
