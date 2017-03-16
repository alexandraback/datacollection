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

const int maxn = 1010;

int n;
char s[maxn];

bool read() {
  if (scanf("%s", s) < 1) {
    return false;
  }
  n = strlen(s);
  return true;
}

void solve() {
  s[n] = '+';
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[i + 1]) {
      ++res;
      reverse(s, s + i + 1);
      for (int j = 0; j <= i; ++j) {
        s[j] = (s[j] == '-' ? '+' : '-');
      }
    }
  }
  printf("%d\n", res);
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



