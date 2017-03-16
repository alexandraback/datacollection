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
int used[maxm];
long long times[maxm];

void solve() {
  int m = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < hs[i]; ++j) {
      ps[m++] = mp(ms[i] + j, ds[i]);
    }
  }
  set<pair<long long, int> > tree;
  for (int i = 0; i < m; ++i) {
    times[i] = (long long) (360 - ps[i].second) * ps[i].first;
    tree.insert(mp(times[i], i));
    used[i] = 0;
  }

  int res = m;

  int add = 0;
  int opened = 0;
  while (add < res) {
    long long time = tree.begin()->first;
    while (add < res && tree.begin()->first <= time) {
      auto iter = tree.begin();
      int v = iter->second;
      tree.erase(iter);
      times[v] += 360ll * ps[v].first;
      if (!used[v]) {
        ++opened;
        used[v] = 1;
      } else {
        ++add;
      }
      tree.insert(mp(times[v], v));
    }
    res = min(res, add + m - opened);
  }
  printf("%d\n", res);
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
