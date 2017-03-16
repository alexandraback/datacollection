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
    int x, r, c; cin >> x >> r >> c;
    if (r > c) {
      swap(r, c);
    }

    if ((r * c) % x) {
      printf("Case #%d: RICHARD\n", cs + 1);
      continue;
    }

    if (x <= 2) {
      printf("Case #%d: GABRIEL\n", cs + 1);
      continue;
    }

    if (x == 3) {
      if (r == 1) {
        printf("Case #%d: RICHARD\n", cs + 1);
      } else {
        printf("Case #%d: GABRIEL\n", cs + 1);
      }
      continue;
    }

    if (x == 4) {
      if (r == 1) {
        printf("Case #%d: RICHARD\n", cs + 1);
      } else if (r == 2) {
        printf("Case #%d: RICHARD\n", cs + 1);
      } else {
        printf("Case #%d: GABRIEL\n", cs + 1);
      }
      continue;
    }

    if (x == 5) {
      if (r <= 2) {
        printf("Case #%d: RICHARD\n", cs + 1);
      } else if (r == 3) {
        if (c == 5) {
          printf("Case #%d: RICHARD\n", cs + 1);
        } else {
          printf("Case #%d: GABRIEL\n", cs + 1);
        }
      } else {
        printf("Case #%d: GABRIEL\n", cs + 1);
      }
      continue;
    }

    if (x == 6) {
      if (r <= 3) {
        printf("Case #%d: RICHARD\n", cs + 1);
      } else {
        printf("Case #%d: GABRIEL\n", cs + 1);
      }
      continue;
    }

    if (x == 7) {
      if (r <= 3) {
        printf("Case #%d: RICHARD\n", cs + 1);
      } else if (r == 4) {
        if (c == 7) {
          printf("Case #%d: RICHARD\n", cs + 1);
        } else {
          printf("Case #%d: GABRIEL\n", cs + 1);
        }
      } else {
        printf("Case #%d: GABRIEL\n", cs + 1);
      }
      continue;
    }

    if (x >= 8) {
      printf("Case #%d: RICHARD\n", cs + 1);
      continue;
    }

    printf("Case #%d: GABRIEL\n", cs + 1);
  }
}
