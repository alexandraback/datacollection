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

const int maxn = 20;

ll pow10[maxn];

void precalc() {
  pow10[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    pow10[i] = pow10[i - 1] * 10;
  }
}

const ll inf = (ll) 1.01e18;

int n;
char s[2][maxn];

bool read() {
  if (scanf("%s%s", s[0], s[1]) < 2) {
    return false;
  }
  assert(strlen(s[0]) == strlen(s[1]));
  return true;
}

ll getmax(char *s, int k) {
  if (k == 0) {
    return 0;
  }

  int a = (s[0] == '?' ? 9 : s[0] - '0');
  return a * pow10[k - 1] + getmax(s + 1, k - 1);
}

ll getmin(char *s, int k) {
  if (k == 0) {
    return 0;
  }

  int a = (s[0] == '?' ? 0 : s[0] - '0');
  return a * pow10[k - 1] + getmin(s + 1, k - 1);
}

bool better(pair<ll, ll> a, pair<ll, ll> b) {
  ll da = abs(a.first - a.second);
  ll db = abs(b.first - b.second);
  if (da != db) {
    return da < db;
  }
  if (a.first != b.first) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

pair<ll, ll> solve(char *s, char *t, int k) {
  if (k == 0) {
    return mp(0, 0);
  }
  int a0 = (s[0] == '?' ? -1 : s[0] - '0');
  int b0 = (t[0] == '?' ? -1 : t[0] - '0');

  pair<ll, ll> res = mp(-inf, inf);

  for (int a = 0; a < 10; ++a) {
    if (a != a0 && a0 != -1) {
      continue;
    }
    for (int b = 0; b < 10; ++b) {
      if (b != b0 && b0 != -1) {
        continue;
      }

      if (a == b && (a0 == -1 && b0 == -1) && a > 0) {
        continue;
      }

      if (a < b) {
        ll ra = getmax(s + 1, k - 1);
        ll rb = getmin(t + 1, k - 1);
        pair<ll, ll> cur = mp(a * pow10[k - 1] + ra, b * pow10[k - 1] + rb);
        if (better(cur, res)) {
          res = cur;
        }
        continue;
      }
      if (a > b) {
        ll ra = getmin(s + 1, k - 1);
        ll rb = getmax(t + 1, k - 1);
        pair<ll, ll> cur = mp(a * pow10[k - 1] + ra, b * pow10[k - 1] + rb);
        if (better(cur, res)) {
          res = cur;
        }
        continue;
      }

      pair<ll, ll> cur = solve(s + 1, t + 1, k - 1);
      cur.first += a * pow10[k - 1];
      cur.second += b * pow10[k - 1];
      if (better(cur, res)) {
        res = cur;
      }
    }
  }

  return res;
}

char *tostr(ll x, int n) {
  char *res = new char[n + 1];
  for (int i = 0; i < n; ++i) {
    res[n - 1 - i] = x % 10 + '0';
    x /= 10;
  }
  res[n] = 0;
  return res;
}

void solve() {
  int n = (int) strlen(s[0]);
  pair<ll, ll> res = solve(s[0], s[1], n);
//  printf("%s %s: ", s[0], s[1]);
  printf("%s %s\n", tostr(res.first, n), tostr(res.second, n));
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
  for (int tn = 1; tn <= T; ++tn) {  
    assert(read());
    printf("Case #%d: ", tn);
    solve();
#ifdef LOCAL
    eprintf("%.18f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}



