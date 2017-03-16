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

char str[1005];

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  int n;
  scanf("%d %s\n", &n, str);
  for (int ans = 0; ans <= 10002; ++ans) {
    bool ok = true;
    int cnt = ans;
    for (int i = 0; i <= n; ++i) {
      if (str[i] == '0') continue;
      if (cnt >= i) cnt += str[i] - '0';
      else {
        ok = false;
        break;
      }
    }
    if (ok) {
      printf("%d\n", ans);
      break;
    }
  }
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