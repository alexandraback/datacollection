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

const int maxn = (int) 1e6 + 10;
int d[maxn];

long long reverse(long long n) {
  static int a[20];
  long long res = 0;
  for (; n; n /= 10) {
    res *= 10;
    res += n % 10;
  }
  return res;
}

void precalc() {
  for (int i = 0; i < maxn; ++i) {
    d[i] = INF;
  }
  d[1] = 1;
  for (int i = 1; i < maxn; ++i) {
    assert(d[i] != INF);
    d[i + 1] = min(d[i + 1], d[i] + 1);
    int ni = reverse(i);
    if (ni < maxn) {
      d[ni] = min(d[ni], d[i] + 1);
    }
  }
}

long long n;

bool read() {
  if (scanf(LLD, &n) < 1) {
    return 0;
  }
  return 1;
}

void solve() {
  printf("%d\n", d[n]);
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
