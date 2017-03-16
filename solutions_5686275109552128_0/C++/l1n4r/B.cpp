
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

const int INF = 1000000000;

int memo[1003][1003];

int comp(const int p, const int r) {
  if (p <= r) {
    return 0;
  }
  if (memo[p][r] < INF) {
    return memo[p][r];
  }

  int& ret = memo[p][r];
  for (int i = 1; i < p; i++) {
    ret = min(ret, 1 + comp(i, r) + comp(p - i, r));
  }
  return ret;
}

int p[1003];

int main() {
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j < i; j++) {
      memo[i][j] = INF;
    }
  }

  int test_cases;
  scanf("%d", &test_cases);

  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int d, pmax = 0;
    scanf("%d", &d);
    for (int i = 0; i < d; i++) {
      scanf("%d", p + i);
      pmax = max(pmax, p[i]);
    }

    int ans = INF;
    for (int r = 1; r <= pmax; r++) {
      int cur = r;
      for (int i = 0; i < d; i++) {
        cur += comp(p[i], r);
      }
      ans = min(ans, cur);
    }

    printf("Case #%d: %d\n", test_case, ans);
  }

  return 0;
}