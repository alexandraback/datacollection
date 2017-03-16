#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

struct State {
  int x;
  int y;
  long long xr;
  long long yr;
  int done;
  State(int _x, int _y, long long _xr, long long _yr, int _done) {
    x = _x; y = _y; xr = _xr; yr = _yr; done = _done;
  }
  bool operator<(const State &s) const {
    if (x != s.x) return x < s.x;
    if (y != s.y) return y < s.y;
    if (xr != s.xr) return xr < s.xr;
    if (yr != s.yr) return yr < s.yr;
    return done < s.done;
  }
};

int N, M;
long long a[101];
int A[100];
long long b[101];
int B[100];
long long res;

void solve(int ai, long long ar, int bi, long long br, set<State> &pool, int now) {
  if (ai == N || bi == M) {
    if (now > res) res = now;
    return;
  }
  State s(ai, bi, ar, br, now);
  if (pool.find(s) != pool.end()) return;
  solve(ai + 1, a[ai + 1], bi, br, pool, now);
  solve(ai, ar, bi + 1, b[bi + 1], pool, now);
  if (A[ai] == B[bi]) {
    int c = min(ar, br);
    ar -= c;
    br -= c;
    if (ar == 0 && br == 0) {
      solve(ai + 1, a[ai + 1], bi + 1, b[bi + 1], pool, now + c);
    } else if (ar == 0) {
      solve(ai + 1, a[ai + 1], bi, br, pool, now + c);
    } else if (br == 0) {
      solve(ai, ar, bi + 1, b[bi + 1], pool, now + c);
    }
  }
  pool.insert(s);
}

int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int ni = 1; ni <= ncase; ++ni) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
      scanf("%lld %d", &a[i], &A[i]);
    }
    for (int j = 0; j < M; ++j) {
      scanf("%lld %d", &b[j], &B[j]);
    }
    res = 0;
    set<State> pool;
    solve(0, a[0], 0, b[0], pool, 0);
    printf("Case #%d: %lld\n", ni, res);
  }

  return 0;
}
