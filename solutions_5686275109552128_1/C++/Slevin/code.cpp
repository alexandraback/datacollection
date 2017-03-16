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

void run() {
  int nn; cin >> nn;
  for (int cs = 0; cs < nn; ++cs) {
    int n; cin >> n;
    vector<int> vi(n);
    for (int i = 0; i < vi.size(); ++i) {
      cin >> vi[i];
    }
    int mx = *max_element(all(vi));
    int res = mx;
    for (int i = 1; i < mx; ++i) {
      int subres = i;
      vector<int> tmp = vi;
      for (int j = 0; j < tmp.size(); ++j) {
        while(tmp[j] > i) {
          ++subres;
          tmp[j] -= i;
        }
      }
      res = min(res, subres);
    }
    printf("Case #%d: %d\n", cs + 1, res);
  }
}
