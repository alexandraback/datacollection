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

long long reverse(long long n) {
  static int a[20];
  long long res = 0;
  for (; n; n /= 10) {
    res *= 10;
    res += n % 10;
  }
  return res;
}


long long n;

bool read() {
  if (scanf(LLD, &n) < 1) {
    return 0;
  }
  return 1;
}

int calc(long long n) {
  if (n == 0) {
    return 0;
  }
  int cnt = 0;
  int a[20];
  for (long long x = n; x > 0; x /= 10) {
    a[cnt++] = x % 10;
  }

  int mid = (cnt + 1) / 2;
  int cur = 0;
  for (int i = mid - 1; i >= 0; --i) {
    cur *= 10;
    cur += a[i];
    a[i] = 0;
  }
  if (cur == 0) {
    return calc(n - 1) + 1;
  }
  n -= cur - 1;
  long long newn = reverse(n);
  if (n == newn) {
    return calc(n - 1) + cur;
  }
  return cur + calc(newn);
}

void solve() {
  printf("%d\n", calc(n));
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

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
