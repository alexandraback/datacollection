
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

char c[1003];

int main() {
  int test_cases;
  scanf("%d", &test_cases);

  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int smax;
    scanf("%d %s", &smax, c);

    int ans = 0;
    int s = c[0] - '0';
    for (int i = 1; i <= smax; i++) {
      const int t = c[i] - '0';
      if (s < i) {
        ans += i - s;
        s += i - s;
      }
      s += t;
    }

    printf("Case #%d: %d\n", test_case, ans);
  }

  return 0;
}