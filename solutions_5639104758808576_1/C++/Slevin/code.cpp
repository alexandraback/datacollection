#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <memory.h>
using namespace std;

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

int ri() {
  static int res;
  scanf("%d", &res);
  return res;
}

template <typename T>
int numbits(T n) {
  return n ? 1 + numbits(n & (n - 1)) : 0;
}

class timer {
public:
  timer() : t_(clock()) {}
  void restart() { t_ = clock(); }
  float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
  clock_t t_;
};

void run();

int main() {
#ifdef LOCAL_HOST
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  timer t;
#endif
  run();
#ifdef LOCAL_HOST
  //printf("\nElapsed time: %.9f\n", t.elapsed());
#endif
  return 0;
}

int arr[1024];

void run() {
  int nn; cin >> nn;
  for (int cs = 0; cs < nn; ++cs) {
    memset(arr, 0, sizeof(arr));
    int res = 0, prev = 0;
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - '0';
      if (i > prev) {
        res += i - prev;
        prev += i - prev;
      }
      prev += c;
    }
    printf("Case #%d: %d\n", cs + 1, res);
  }
}
