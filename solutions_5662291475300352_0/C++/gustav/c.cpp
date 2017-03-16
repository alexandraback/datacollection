#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const double eps = 1e-9;

bool lt(double a, double b) { return a + eps < b; }
bool gt(double a, double b) { return lt(b, a); }
bool eq(double a, double b) { return !lt(a, b) && !gt(a, b); }
bool lte(double a, double b) { return !gt(a, b); }
bool gte(double a, double b) { return !lt(a, b); }

struct Hiker {
  double start;
  double speed;
};

void solve() {
  int n;
  scanf("%d", &n);
  vector< Hiker > v;
  REP(i, n) {
    int D, H, M;
    scanf("%d%d%d", &D, &H, &M);
    REP(j, H) v.push_back({D / 360.0, double(M + j)});
  }

  assert((int)v.size() == 2);

  if (gt(v[0].start, v[1].start))
    swap(v[0].start, v[1].start);

  if (eq(v[0].speed, v[1].speed)) {
    puts("0");
    return;
  }

  if (gt(v[1].speed, v[0].speed)) {
    double p0 = 1.0 - v[0].start;
    double t0 = p0 / v[0].speed;
    double p1 = t0 * v[1].speed;
    if (gte(p1, 2.0 - v[1].start)) {
      puts("1");
      return;
    } else {
      puts("0");
      return;
    }
  }

  if (lt(v[1].speed, v[0].speed)) {
    double delta = v[1].start - v[0].start;
    double t = delta / (v[0].speed - v[1].speed);
    double p = t * v[0].speed;

    if (gte(p, 1.0)) {
      puts("0");
      return;
    }

    double p1 = 1.0 - p;
    double t1 = p1 / v[1].speed;
    double p0 = t1 * v[0].speed;
    if (gte(p0, 2.0 - p)) {
      puts("1");
      return;
    } else {
      puts("0");
      return;
    }
  }

  assert(false);
}

int main(void) 
{
  int T;
  scanf("%d", &T);
  FOR(tc, 1, T + 1) {
    printf("Case #%d: ", tc);
    solve();
  }
  return 0;
}
