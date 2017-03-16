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
  vector<int> v1, v2;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    double a;
    scanf("%lf", &a);
    v1.push_back(a * 1000000 + 0.5);
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < n; ++i) {
    double a;
    scanf("%lf", &a);
    v2.push_back(a * 1000000 + 0.5);
  }
  sort(v2.begin(), v2.end());
  int y = 0, z = 0;
  bool used[1002] = {0};
  for (int i = 0; i < v1.size(); ++i) {
    bool ok = true;
    for (int j = 0; j < v2.size(); ++j)
      if (!used[j] && v2[j] > v1[i]) {
        ok = false;
        used[j] = true;
        break;
      }
    z += ok;
  }
  memset(used, 0, sizeof(used));
  for (int i = 0; i < v1.size(); ++i) {
    bool ok = false;
    for (int j = 0; j < v2.size(); ++j)
      if (!used[j] && v2[j] < v1[i]) {
        ok = true;
        used[j] = true;
        break;
      }
    if (ok) {
      ++y;
    } else {
      for (int j = v2.size(); j >= 0; --j)
        if (!used[j]) {
          used[j] = false;
          break;
        }
    }
  }
  printf(" %d %d\n", y, z);
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