/* 
  2014.03.26 15:10
  http://codeforces.ru/gym/100289/
*/


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &v[i]);
  int ans = 1002;
  for (int mx = 1; mx <= 1000; ++mx) {
    int cur = mx;
    for (int i = 0; i < n; ++i) {
      cur += (v[i] - 1) / mx;
    }
    ans = min(ans, cur);
  }
  printf("%d\n", ans);
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}