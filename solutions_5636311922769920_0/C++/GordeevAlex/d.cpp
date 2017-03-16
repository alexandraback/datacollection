#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <complex>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long ll;
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
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stdout)
#define sz(x) ((int)(x).size())
#define TASKNAME ""

void precalc() {
}

int k, c, s;

bool read() {
  if (scanf("%d%d%d", &k, &c, &s) < 3) {
    return false;
  }
  return true;
}

void solve() {
  if ((k + c - 1) / c > s) {
    printf("IMPOSSIBLE\n");
    return;
  }
  for (int i = 0; i < k; ) {
    ll x = 0;
    for (int j = 0; i < k && j < c; ++j, ++i) {
      x = x * k + i;
    }
    printf("%lld%c", x + 1, " \n"[i == k]);
  }
}

int main() {
  srand(rdtsc());
#ifdef LOCAL 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
//  freopen(TASKNAME".in", "r", stdin);
//  freopen(TASKNAME".out", "w", stdout);
#endif

  precalc();
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    assert(read());
    printf("Case #%d: ", i + 1);
    solve();
#ifdef LOCAL
    eprintf("%.18f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}



