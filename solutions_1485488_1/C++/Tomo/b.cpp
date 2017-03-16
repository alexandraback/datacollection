#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;

#define REP(i, n)      for (int (i) = 0, __n = (int)(n); (i) < __n; ++(i))
#define REPS(i, s, n)  for (int (i) = (s), __n = (int)(n); (i) < __n; ++(i))
#define REPD(i, n)     for (int (i) = (n); (i) >= 0; --(i))
#define FOREACH(i, x)  for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define SIZE(x)        (int)((x).size())

const double INF  = 20000000000.0;
const double EPS  = 1e-9;
const int    MAXN = 100;

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };

double d[MAXN][MAXN];
int    C[MAXN][MAXN], F[MAXN][MAXN];
int    H, N, M;

struct pos {
  int    r, c;
  double w;

  pos(int _r, int _c, double _w) : r(_r), c(_c), w(_w) {}
  bool operator<(pos const& b) const {
    return w > b.w;
  }
  bool final() const {
    return r == N-1 && c == M-1;
  }
};

double cost(int cr, int cc, int nr, int nc, double w, bool& valid) {
  if (C[nr][nc] - F[nr][nc] < 50) { valid = false; return INF; }
  if (C[nr][nc] - F[cr][cc] < 50) { valid = false; return INF; }
  if (C[cr][cc] - F[nr][nc] < 50) { valid = false; return INF; }

  double nw = max(w, (H + 50.0 - C[nr][nc]) / 10.0);
  double L  = max<double>(F[cr][cc], H - nw * 10.0);

  valid = true;
  if (nw < EPS) return 0.0;
  return nw + ((L - F[cr][cc] - 20.0 > -EPS) ? 1.0 : 10.0);
} 

void shortest_path() {
  priority_queue<pos> Q;

  d[0][0] = 0.0; Q.push(pos(0, 0, 0.0));
  while (!Q.empty()) {
    pos    top = Q.top(); Q.pop();
    double w   = top.w;
    int    r   = top.r, c = top.c;

    if (top.final()) break;
    if (fabs(w - d[r][c]) > EPS) continue;

    REP(k, 4) {
      int nr = r + dr[k], nc = c + dc[k];
      if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;

      bool   valid;
      double nw = cost(r, c, nr, nc, w, valid);

      if (!valid) continue;
      if (nw < d[nr][nc]) d[nr][nc] = nw, Q.push(pos(nr, nc, nw));
    }
  }
}

int main() {
  int T; scanf("%d", &T);
  REP(tc, T) {
    scanf("%d%d%d", &H, &N, &M);
    REP(i, N) REP(j, M) scanf("%d", &C[i][j]);
    REP(i, N) REP(j, M) scanf("%d", &F[i][j]);

    REP(i, N) REP(j, M) d[i][j] = INF;
    shortest_path();

    printf("Case #%d: %.8lf\n", tc+1, d[N-1][M-1]);
  }
  return EXIT_SUCCESS;
}
