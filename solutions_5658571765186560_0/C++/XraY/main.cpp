#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int INF = (int)1e9 + 1;
const ld EPS = 1e-9;

void precalc() {
}

int x, w, h;

bool read() {
  if (scanf("%d%d%d", &x, &w, &h) < 3) {
    return 0;
  }
  return 1;
}

void solve() {
  if (w < h) {
    swap(w, h);
  }
  bool res = 0;
  if (x >= 7 || w * h % x || w < x || h < (x + 1) / 2) {
    res = 1;
  } else {
    if (x > 3) {
      if (x == 4) {
        if (h == 2) {
          res = 1;
        }
      } else {
        if (x == 5) {
          if (h == 3) {
            res = 1;
          }
        } else {
          assert(x == 6);
          if (h == 3) {
            res = 1;
          }
        }
      }
    }
  }
  printf(!res ? "GABRIEL\n" : "RICHARD\n");
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  precalc();
  int maxt;
  while (scanf("%d", &maxt) == 1) {
    for (int t = 0; t < maxt; ++t) {
      assert(read());
      printf("Case #%d: ", t + 1);
      solve();
#ifdef DEBUG
      eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }
  }
  return 0;
}
