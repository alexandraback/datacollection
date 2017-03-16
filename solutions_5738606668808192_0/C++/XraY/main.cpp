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

#define left mleft
int n, left;

bool read() {
  if (scanf("%d%d", &n, &left) < 2) {
    return 0;
  }
  return 1;
}

void solve() {
  vector<unsigned> ans;
  while (left) {
    unsigned mask = 0;
    for (int i = 0; i < n; ++i) {
      mask ^= ((unsigned) ((!i || i == n - 1) ? 1 : rnd(2)) << i);
    }
    if (find(ans.begin(), ans.end(), mask) != ans.end()) {
      continue;
    }
    bool ok = 1;
    vector<int> a;
    for (int mod = 2; mod <= 10; ++mod) {
      ok = 0;
      for (int p = 2; p <= (int) 1e2; ++p) {
        int rem = 0;
        int x = 1;
        for (int i = 0; i < n; ++i) {
          if ((mask >> i) & 1) {
            rem += x;
            rem %= p;
          }
          x = x * mod % p;
        }
        if (!rem) {
          a.pb(p);
          ok = 1;
          break;
        }
      }
      if (!ok) {
        break;
      }
    }
    if (ok) {
      ans.pb(mask);
      for (int i = n - 1; i >= 0; --i) {
        printf("%d", ((mask >> i) & 1));
      }
      for (int i = 0; i < sz(a); ++i) {
        printf(" %d", a[i]);
      }
      printf("\n");
      --left;
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
      printf("Case #%d:\n", t + 1);
      solve();
#ifdef DEBUG
      eprintf("Time: %.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }
  }
  return 0;
}
