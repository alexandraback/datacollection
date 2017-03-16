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
#include <queue>

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

const int INF = (int) 1.01e9;
const ld EPS = 1e-9;

const ld PI = acos(-1.0L);

void precalc() {
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  return 1;
}

void solve() {
  if (!n) {
    printf("INSOMNIA\n");
    return;
  }
  int mask = 0;
  for (int x = n;; x += n) {
    assert(x < 100 * n);
    for (int y = x; y; y /= 10) {
      mask |= (1 << (y % 10));
    }
    if (mask == (1 << 10) - 1) {
      printf("%d\n", x);
      break;
    }
  }
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
      eprintf("Time: %.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }
  }
  return 0;
}
