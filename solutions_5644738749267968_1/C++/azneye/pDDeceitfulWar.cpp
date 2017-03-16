/*
 * 
 * File:   pDDeceitfulWar.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Apr 11, 2014, 8:54:20 PM
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

namespace pDDeceitfulWar {

void solve(int test_num) {
  int N;
  static double a[1111], b[1111];
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> a[i];
  for (int i = 0; i < N; i++)
    cin >> b[i];
  sort(a, a + N);
  sort(b, b + N);
  int norm = N, cheat = 0;
  for (int i = 0, j = 0; i < N; i++, j++) {
    while (j < N && a[i] > b[j])
      j++;
    if (j == N)
      break;
    norm--;
  }
  //plnarr(a, a + N);
  //plnarr(b, b + N);
  while (true) {
    bool ok = true;
    for (int j = 0; j < cheat; j++)
      if (b[j] > a[j + N - cheat])
        ok = false;
    if (!ok)
      break;
    cheat++;
  }
  printf("Case #%d: %d %d\n", test_num, cheat - 1, norm);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  pDDeceitfulWar::solve();
  return 0;
}
