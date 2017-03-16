#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;


char str[10005];

void Solve() {
  int n;
  cin >> n;
  if (n == 0) {
    puts("INSOMNIA");
  } else {
    std::set<int> s;
    int ret = n;
    while (true) {
      int x = ret;
      while (x) {
        s.insert(x % 10);
        x /= 10;
      }
      if (s.size() == 10) {
        break;
      }
      ret += n;
    }
    printf("%d\n", ret);
  }
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
