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

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

bool was[10];

void solve() {
  if (n == 0) {
    printf("INSOMNIA\n");
    return;
  }
  memset(was, 0, sizeof(was));
  int cnt = 0;
  ll x = n;
  for (; cnt < 10; x += n) {
    for (ll y = x; y; y /= 10) {
      int d = y % 10;
      if (!was[d]) {
        ++cnt;
        was[d] = true;
      }
    }
  }
  x -= n;
  printf("%lld\n", x);
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


