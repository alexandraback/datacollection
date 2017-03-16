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

void precalc() {
}

int n;
long long times;

const int maxn = (int) 1e4 + 10;
char s[maxn + 1];

bool read() {
  if (scanf("%d" LLD "%s", &n, &times, s) < 3) {
    return 0;
  }
  assert((int) strlen(s) == n);
  return 1;
}

struct Quad {
  int val;
  int neg;

  Quad() {}
  Quad(int _val, int _neg) : val(_val), neg(_neg) {}
  Quad(char ch) : neg(0) {
    if (ch == 'i') {
      val = 0;
    } else {
      if (ch == 'j') {
        val = 1;
      } else {
        assert(ch == 'k');
        val = 2;
      }
    }
  }

  inline Quad operator * (const Quad &q) const {
    Quad res(3 ^ val ^ q.val, neg ^ q.neg);
    if (val == -1 || q.val == -1) {
      res.val = (val == -1) ? q.val : val;
    } else {
      if (val == q.val) {
        res.val = -1;
        res.neg ^= 1;
      } else {
        if (((val + 1) % 3) != q.val) {
          res.neg ^= 1;
        }
      }
    }
    return res;
  }

  inline bool operator == (const Quad &q) {
    return val == q.val && neg == q.neg;
  }

  inline bool operator != (const Quad &q) {
    return val != q.val || neg != q.neg;
  }
};

Quad pref[maxn + 1];

void solve() {
  long long res = 0;
  for (int rot = 0; rot < 2; ++rot) {
    pref[0] = Quad(-1, 0);
    for (int i = 0; i < n; ++i) {
      if (!rot) {
        pref[i + 1] = (pref[i] * Quad(s[i]));
      } else {
        pref[i + 1] = (Quad(s[i]) * pref[i]);
      }
    }
    if (!rot) {
      Quad res = Quad(-1, 0);
      for (int iter = 0; iter < (int) (times & 3ll); ++iter) {
        res = res * pref[n];
      }
      if (res != Quad(-1, 1)) {
        printf("NO\n");
        return;
      }
    }
    Quad toadd(-1, 0);
    int value = -1;
    for (int iter = 0; iter < 4; ++iter) {
      for (int i = 0; value == -1 && i < n; ++i) {
        Quad cur = (!rot ? (toadd * pref[i]) : (pref[i] * toadd));
        if (cur != Quad(!rot ? 0 : 2, 0)) {
          continue;
        }
        value = iter * n + i;
      }
      toadd = toadd * pref[n];
    }
    assert(toadd == Quad(-1, 0));
    reverse(s, s + n);
    if (value == -1) {
      res += (long long) 1e18;
    } else {
      res += value;
    }
    //eprintf("value = %d\n", value);
  }
  if (res > times * n) {
    printf("NO\n");
  } else {
    printf("YES\n");
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
      eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }
  }
  return 0;
}
