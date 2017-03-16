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

const int maxn = 1e2 + 10;

bool isp[maxn];
vector<int> p;

void precalc() {
  memset(isp, true, sizeof(isp));
  p.clear();
  for (int i = 2; i < maxn; ++i) {
    if (!isp[i]) {
      continue;
    }
    p.pb(i);
    for (ll j = (ll) i * i; j < maxn; j += i) {
      isp[j] = false;
    }
  }
}

int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

vector<ll> ans;
vector<int> ps[11];

int cur[11];

void solve() {
  random_shuffle(p.begin(), p.end());
  ans.clear();
  for (int i = 2; i <= 10; ++i) {
    ps[i].clear();
  }
  for (ll mask = 0; sz(ans) < k && mask < (1ll << n); ++mask) {
    if (!(mask & 1) || !((mask >> (n - 1) & 1))) {
      continue;
    }
    bool good = true;
    for (int b = 2; b <= 10; ++b) {
      cur[b] = -1;
      for (int i = 0; i < sz(p); ++i) {
        int cp = p[i];
        int rem = 0;
        for (int x = 1, j = 0; j < n; ++j, x = (x * b) % cp) {
          if ((mask >> j) & 1) {
            rem += x;
          }
        }
        rem %= cp;
        if (rem == 0) {
          cur[b] = cp;
          break;
        }
      }
      if (cur[b] == -1) {
        good = false;
        break;
      }
    }

    if (!good) {
      continue;
    }

    ans.pb(mask);
    for (int i = 2; i <= 10; ++i) {
      ps[i].pb(cur[i]);
    }
  }

  assert(sz(ans) == k);
  for (int i = 0; i < k; ++i) {
    static char buf[100];
    for (int j = 0; j < n; ++j) {
      buf[n - 1 - j] = ((ans[i] >> j) & 1) + '0';
    }
    buf[n] = 0;
    printf("%s ", buf);
    for (int j = 2; j <= 10; ++j) {
      printf("%d%c", ps[j][i], " \n"[j == 10]);
    }
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
    printf("Case #%d:\n", i + 1);
    solve();
#ifdef LOCAL
    eprintf("%.18f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}



