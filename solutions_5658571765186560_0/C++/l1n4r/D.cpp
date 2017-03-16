
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

int main() {
  int test_cases;
  scanf("%d", &test_cases);

  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int x, r, c;
    scanf("%d %d %d", &x, &r, &c);
    if (r > c) {
      swap(r, c);
    }

    bool Richard = true;
    if (x == 1) {
      Richard = false;
    } else if (x == 2) {
      if ((r * c) % 2 == 0) {
        Richard = false;
      }
    } else if (x == 3) {
      if (r >= 2 && (r * c) % 3 == 0) {
        Richard = false;
      }
    } else if (x == 4) {
      if (r >= 3 && c == 4) {
        Richard = false;
      }
    }

    printf("Case #%d: %s\n", test_case, (Richard) ? "RICHARD" : "GABRIEL");
  }

  return 0;
}