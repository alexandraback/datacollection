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

const int INF = (int)1e9 + 5e5 + 10;
const ld EPS = 1e-9;

void precalc() {
}

int n;
const int maxn = (int) 1e3 + 10;
int ds[maxn], hs[maxn], ms[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &ds[i], &hs[i], &ms[i]);
  }
  return 1;
}

const int maxm = (int) 5e5 + 10;
pair<int, int> ps[maxm];

void solve() {
  int m = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < hs[i]; ++j) {
      ps[m++] = mp(ms[i] + j, ds[i]);
    }
  }
  if (m == 1) {
    printf("0\n");
    return;
  }
  if (m == 2) {
    int res = 1;
    long long t1 = -1e18, t2 = 1e18;
    for (int i = 0; i < m; ++i) {
      t1 = max(t1, (long long) (360 - ps[i].second) * ps[i].first);
      t2 = min(t2, (long long) (720 - ps[i].second) * ps[i].first);
    }
    printf("%d\n", (t1 >= t2));
    return;
  }
  assert(m == 4);
  printf("0\n");
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
