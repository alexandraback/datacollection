#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cctype>
using namespace std;

typedef long double Real;

const Real o = 1e-8;
const Real oo = 1e+20;
const Real pi = acos(-1.0);
const int max_n = 128;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct Comparer {
  bool operator()(const pair<pair<int, int>, Real> &a,
                  const pair<pair<int, int>, Real> &b) {
    return a.second < b.second;
  }
};

multiset<pair<pair<int, int>, Real>, Comparer> q;
Real h0;
int m, n, T, I;
int c[max_n][max_n], f[max_n][max_n];
Real d[max_n][max_n];

void input() {
  cin >> h0 >> m >> n;
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < n; ++y) {
      cin >> c[x][y];
    }
  }
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < n; ++y) {
      cin >> f[x][y];
    }
  }
}

void movable(int x, int y, int x1, int y1, Real t, Real h, int delta,
             Real &t1, Real &h1) {
  if (c[x][y] - 50 < f[x1][y1]) {
    t1 = oo;
    return;
  }
  if (f[x][y] + 50 > c[x1][y1]) {
    t1 = oo;
    return;
  }
  if (f[x1][y1] + 50 > c[x1][y1]) {
    t1 = oo;
    return;
  }
  if (h + 50 <= c[x1][y1] + o) {
    t1 = t;
    h1 = h;
    return;
  }
  if (delta == 0) {
    t1 = oo;
    return;
  }
  t1 = t + (h + 50 - c[x1][y1]) / delta;
  h1 = c[x1][y1] - 50;
}

bool outside(int x, int y) {
  return x < 0 || x >= m || y < 0 || y >= n;
}

void bfs(int delta) {
  while (!q.empty()) {
    int x = q.begin()->first.first;
    int y = q.begin()->first.second;
    Real t = q.begin()->second;
    q.erase(q.begin());

    // fprintf(stderr, "(%d, %d) = %.9Lf\n", x, y, t);
    if (d[x][y] <= t + o)
      continue;
    // fprintf(stderr, "(%d, %d) = %.9Lf\n", x, y, t);
    d[x][y] = t;

    Real h = h0 - t * delta;
    for (int dir = 0; dir < 4; ++dir) {
      int x1 = x + dx[dir], y1 = y + dy[dir];
      if (outside(x1, y1))
        continue;
      // t1 = t leaving
      Real t1, h1;
      movable(x, y, x1, y1, t, h, delta, t1, h1);
      if (t1 < oo - o) {
        if (h1 - f[x][y] >= 20 - o)
          q.insert(make_pair(make_pair(x1, y1), t1 + 1));
        else
          q.insert(make_pair(make_pair(x1, y1), t1 + 10));
      }
    }
  }
}

void solve() {
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < n; ++y)
      d[x][y] = oo;
  }
  q.clear();
  q.insert(make_pair(make_pair(0, 0), 0));
  bfs(0);

#if 0
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < n; ++y) {
      printf("%.5Lf\t", d[x][y]);
    }
    printf("\n");
  }
#endif

  q.clear();
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < n; ++y) {
      if (d[x][y] < oo - o) {
        // fprintf(stderr, "(%d, %d) == 0\n", x, y);
        q.insert(make_pair(make_pair(x, y), 0));
      }
    }
  }
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < n; ++y)
      d[x][y] = oo;
  }
  bfs(10);
}

void output() {
#if 0
  for (int x = 0; x < m; ++x) {
    for (int y = 0; y < n; ++y) {
      printf("%.5Lf\t", d[x][y]);
    }
    printf("\n");
  }
#endif
  assert(d[m - 1][n - 1] < oo - o);
  printf("Case #%d: %.9Lf\n", I + 1, d[m - 1][n - 1]);
}

int main() {
  cin >> T;
  for (I = 0; I < T; ++I) {
    input();
    solve();
    output();
  }
	return 0;
}
