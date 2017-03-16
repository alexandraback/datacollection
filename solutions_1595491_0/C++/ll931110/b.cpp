#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int T,n,s,p;
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) {
    scanf("%d %d %d", &n, &s, &p);
    int ret = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      if (x >= 3 * p - 2) ret++;
      else if (x >= 2 && x >= 3 * p - 4 && s > 0) {
        s--;  ret++;
      }
    }
    printf("Case #%d: %d\n", it, ret);
  }
}
