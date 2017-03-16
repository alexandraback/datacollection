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

int k, c, s;

bool read() {
  if (scanf("%d%d%d", &k, &c, &s) < 3) {
    return 0;
  }
  return 1;
}

const int maxn = 100 + 10;
long long pws[maxn];

void solve() {
  if (s * c < k) {
    printf("IMPOSSIBLE\n");
    return;
  }
  pws[0] = 1;
  for (int i = 1; i <= c; ++i) {
    pws[i] = pws[i - 1] * k;
  }
  vector<long long> ans;
  for (int i = 0; i < (k + c - 1) / c; ++i) {
    long long val = 0;
    for (int j = 0; j < c; ++j) {
      val += min(k - 1, i * c + j) * pws[j];
    }
    ans.pb(val);
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  for (int i = 0; i < sz(ans); ++i) {
    printf(LLD "%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
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
