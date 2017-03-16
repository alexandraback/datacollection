/*
 *
 * File:   pCGoodLuck.cpp
 * Author: Andy Y.F. Huang
 * Created on April 26, 2013, 9:43 PM
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

namespace pCGoodLuck {
int len, upto, subsets;
int prods[11];
int poss[111];

void solve(int test_num) {
  for (int i = 0; i < subsets; i++)
    scanf("%d", prods + i);
  for (int a = 2; a <= upto; a++)
    for (int b = 2; b <= upto; b++)
      for (int c = 2; c <= upto; c++) {
        poss[0] = a;
        poss[1] = b;
        poss[2] = c;
        poss[3] = a * b;
        poss[4] = a * c;
        poss[5] = b * c;
        poss[6] = a * b * c;
        poss[7] = 1;
        //plnarr(poss, poss + 8);
        bool ok = true;
        for (int i = 0; i < subsets; i++)
          if (find(poss, poss + 8, prods[i]) == poss + 8) {
            ok = false;
            break;
          }
        if (ok) {
          printf("%d%d%d\n", a, b, c);
          return;
        }
      }
}

void solve() {
  #ifdef AZN
  freopen("inputC.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  int tests;
  scanf("%d", &tests);
  scanf("%d %d %d %d", &tests, &len, &upto, &subsets);
  printf("Case #1:\n");
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  pCGoodLuck::solve();
  return 0;
}

