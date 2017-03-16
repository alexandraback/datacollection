#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <assert.h>
using namespace std;

const double eps = 1e-8, inf = 1e+9, pi = acos(-1.0);

inline int sign(double x) { 
  return x < -eps ? -1 : x > eps; 
}

inline double sqr(double x) { 
  return x * x; 
}

int sqri(int x) {
  return x * x;
}

/* ---------- points ---------- */

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}

  bool operator<(const point &p) const { 
    return sign(x - p.x) * 2 + sign(y - p.y) < 0; 
  }
  bool operator>(const point &p) const { 
    return p < *this;
  }
  bool operator==(const point &p) const { 
    return !sign(x - p.x) && !sign(y - p.y); 
  }
};

inline double cross(point a, point b, point c) {
  return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

double dist2(point a, point b) {
  return sqr(a.x - b.x) + sqr(b.y - a.y);
}

/* PA * PB */
double dot(point p, point a, point b) {
  return (a.x - p.x) * (b.x - p.x) + (a.y - p.y) * (b.y - p.y);
}

/* ---------- lines ---------- */

struct line {
  point p, q;
  line() {}
  line(point p, point q) : p(p), q(q) {}
};

int parallel(line u, line v) {
  return !sign((u.p.x - u.q.x) * (v.p.y - v.q.y) - (v.p.x - v.q.x) * (u.p.y - u.q.y));
}

/* same side: 1; at least one of a, b touches l: 0; otherwise -1 */
int side(line m, point p, point q) {
  return sign(cross(m.p, m.q, p)) * sign(cross(m.p, m.q, q));
}

/* intersection point */
point ip(line u, line v) {
  double n = (u.p.y - v.p.y) * (v.q.x - v.p.x) - (u.p.x - v.p.x) * (v.q.y - v.p.y);
  double d = (u.q.x - u.p.x) * (v.q.y - v.p.y) - (u.q.y - u.p.y) * (v.q.x - v.p.x);
  double r = n / d;
  return point(u.p.x + r * (u.q.x - u.p.x), u.p.y + r * (u.q.y - u.p.y));
}

line perpendicular(line l, point a) {
  return line(a, point(a.x + l.p.y - l.q.y, a.y + l.q.x - l.p.x));
}

point pedal(line l, point a) {
  return ip(l, perpendicular(l, a));
}

point mirror(line l, point a) {
  point p = pedal(l, a);
  return point(p.x * 2 - a.x, p.y * 2 - a.y);
}

/* u: p->q, v: mirror */
inline int in1(line u, line v) {
  return side(u, v.p, v.q) <= 0 && side(v, u.p, u.q) < 0;
}

int myround(double x) {
  int i = (int)x;
  int k = i;
  for (int j = i - 1; j <= i + 1; j++)
    if (fabs(x - j) < fabs(x - k))
      k = j;
  return k;
}

int merge(line &u, line &v) {
  if (u.p > u.q) swap(u.p, u.q);
  if (v.p > v.q) swap(v.p, v.q);
  if (!sign(cross(u.p, u.q, v.p)) && !sign(cross(u.p, u.q, v.q))) {
    if (u.q < v.p) return 0;
    if (v.q < u.p) return 0;
    u.p = min(u.p, v.p);
    u.q = max(u.q, v.q);
    return 1;
  }
  return 0;
}

const int N = 32;

const int dx[] = { 1, 1, -1, -1, 0, 0, 1, -1 };
const int dy[] = { 1, -1, -1, 1, 1, -1, 0, 0 };

int n, m, d;
int si, sj, ln;
char map[N][N];
point st;
line ls[N * N * 4];
int del[N * N * 4];
int mark[N][N];
int qq[N * N], qs, qt;

int solve(point u, point v) {
  while (1) {
    line l(u, v), *lz = NULL;
    point best;
    double dmin = inf;
    if (!sign(cross(u, v, st)) && sign(dot(u, v, st)) > 0)
      dmin = dist2(best = st, u);
    for (int i = 0; i < ln; i++) {
      if (in1(l, ls[i])) {
        point p = ip(l, ls[i]);
        double d2 = dist2(p, u);
        if (dmin > d2) {
          dmin = d2;
          best = p;
          lz = &ls[i];
        }
      }
    }
    if (dmin == inf)
      return v == st;
    if (best == st)
      return v == st;
    int bx = myround(best.x);
    int by = myround(best.y);
    if (!sign(bx - best.x) && !sign(by - best.y) && bx % 2 == 0 && by % 2 == 0) {
      int i = bx / 2;
      int j = by / 2;
      int z0 = map[i - 1][j - 1] == '#';
      int z1 = map[i - 0][j - 1] == '#';
      int z2 = map[i - 0][j - 0] == '#';
      int z3 = map[i - 1][j - 0] == '#';
      if (u.x > best.x) {
        swap(z0, z1);
        swap(z2, z3);
      }
      if (u.y > best.y) {
        swap(z0, z3);
        swap(z1, z2);
      }
      int zs = z0 + z1 + z2 + z3;
      assert(z0 == 0);
      assert(zs > 0);
      if (zs == 3) {
        v.x = 2 * best.x - v.x;
        v.y = 2 * best.y - v.y; // double reflect
        u = best;
      } else if (zs == 2) {
        if (z1 && z2) {
          v.x = 2 * best.x - v.x; // reflect
          u = best;
        } else if (z2 && z3) {
          v.y = 2 * best.y - v.y; // reflect
          u = best;
        } else if (z1 && z3) {
          // through
          u = best;
        } else assert(0);
      } else if (zs == 1) {
        if (z2) {
          return 0;
        } else {
          // through
          u = best;
        }
      }
    } else {
      if (!sign(bx - best.x) && bx % 2 == 0)
        v.x = best.x * 2 - v.x;
      else
        v.y = best.y * 2 - v.y;
      u = best;
    }
  }
}

int main(int argc, char **argv) {
  int T;
  scanf("%d", &T);
  int ss = 1, tt = T;
  if (argc == 3) {
    sscanf(argv[1], "%d", &ss);
    sscanf(argv[2], "%d", &tt);
  }
  for (int t = 1; t <= T; t++) {
    scanf("%d %d %d", &n, &m, &d);
    ln = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", map[i]);
      for (int j = 0; j < m; j++) {
//        if (map[i][j] == '.' && rand() % 2)
//            map[i][j] = '#';
        if (map[i][j] == 'X') {
          si = i;
          sj = j;
          st = point(i + i + 1, j + j + 1);
        }
      }
    }
    if (t < ss || t > tt) continue;

    qs = qt = 0;
    qq[qt++] = si * N + sj;
    memset(mark, 0, sizeof mark);
    mark[si][sj] = 1;
    while (qs < qt) {
      int i = qq[qs] / N;
      int j = qq[qs] % N;
      qs++;
      for (int z = 0; z < 8; z++) {
        int i1 = i + dx[z];
        int j1 = j + dy[z];
        if (!mark[i1][j1]) {
          mark[i1][j1] = 1;
          if (map[i1][j1] != '#')
            qq[qt++] = i1 * N + j1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (map[i][j] == '#' && mark[i][j]) {
          point a(i + i + 0, j + j + 0);
          point b(i + i + 2, j + j + 0);
          point c(i + i + 2, j + j + 2);
          point d(i + i + 0, j + j + 2);
          ls[ln++] = line(a, b);
          ls[ln++] = line(b, c);
          ls[ln++] = line(c, d);
          ls[ln++] = line(d, a);
        } 
    }

    memset(del, 0, sizeof del);
    for (int i = 0; i < ln; i++)
      for (int j = i + 1; j < ln; j++)
        if (ls[i].p == ls[j].q && ls[i].q == ls[j].p)
          del[i] = del[j] = 1;
    int ln1 = 0;
    for (int i = 0; i < ln; i++)
      if (!del[i])
        ls[ln1++] = ls[i];
    ln = ln1;

    for (int z = 0; z < 100; z++) {
      int change = 0;
      for (int i = 0; i < ln; i++)
        for (int j = i + 1; j < ln; j++)
          if (merge(ls[i], ls[j])) {
            ls[j--] = ls[--ln];
            change = 1;
          }
      if (!change) break;
    }

    int ans = 0;
    for (int i = -d; i < n + d; i++)
      for (int j = -d; j < m + d; j++) if (sqri(si - i) + sqri(sj - j) <= sqri(d) && (si != i || sj != j)) {
        int s = solve(st, point(i + i + 1, j + j + 1));
//        if (s) printf("%d,%d\n", i, j);
        ans += s;
      }
    printf("Case #%d: %d\n", t, ans);
    fprintf(stderr, "case %d\n", t);
  }
  return 0;
}
