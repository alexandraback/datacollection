/*
 * Code Jam 2013 Round 1C A
 * File:   pAConsonants.cpp
 * Author: Andy Y.F. Huang
 * Created on May 12, 2013, 6:21 AM
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

namespace pAConsonants {
char str[1000111];

bool isvowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void solve(int test_num) {
  int N;
  scanf("%s %d", str, &N);
  long long res = 0;
  int len = strlen(str), last = -1, cnt = 0;
  for (int i = 0; i < len; i++) {
    if (!isvowel(str[i]))
      cnt++;
    else cnt = 0;
    if (cnt >= N) last = i - N + 1;
    res += last + 1;
  }
  printf("Case #%d: %lld\n", test_num, res);
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
  pAConsonants::solve();
  return 0;
}

