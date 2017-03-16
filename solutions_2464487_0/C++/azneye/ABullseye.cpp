/*
 *
 * File:   ABullseye.cpp
 * Author: Andy Y.F. Huang
 * Created on April 26, 2013, 9:05 PM
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

namespace ABullseye {
typedef long long llong;

llong sq(int x) {
  return (llong) x * x;
}

void solve(int test_num) {
  int R, amount, ans = 0;
  scanf("%d %d", &R, &amount);
  for (int r = R + 1; ; r += 2) {
    if (sq(r) - sq(r - 1) <= amount) {
      ans++;
      amount -= sq(r) - sq(r - 1);
    }
    else break;
  }
  printf("Case #%d: %d\n", test_num, ans);
}

void solve() {
  #ifdef AZN
  freopen("inputA.in", "r", stdin);
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
  ABullseye::solve();
  return 0;
}

