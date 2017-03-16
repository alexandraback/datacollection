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
  bool operator==(const point &p) const { 
    return !sign(x - p.x) && !sign(y - p.y); 
  }
};

void read(point *p) {
  scanf("%lf %lf", &p->x, &p->y);
}

void print(point p) {
  printf("%.3lf %.3lf\n", p.x, p.y);
}

point operator-(point a, point b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

double cross(point a, point b, point c) {
  return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

/* mid point */
point mp(point a, point b) {
  return point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

/* next point */ 
point np(point a, double alpha, double d) {
  return point(a.x + d * cos(alpha), a.y + d * sin(alpha));
}

/* PA * PB */
double dot(point p, point a, point b) {
  return (a.x - p.x) * (b.x - p.x) + (a.y - p.y) * (b.y - p.y);
}

/* delta angle of ABC */
inline double delta_angle(point a, point b, point c) {
  return acos(dot(b, a, c) / (dist(a, b) * dist(b, c)));
}

/* if ABC a sharp triangle */
int sharp(point a, point b, point c) {
  return sign(dot(a, b, c)) > 0 && sign(dot(b, a, c)) > 0 && sign(dot(c, a, b)) > 0;
}

double fix(double a, double b = 0) {
  a -= b;
  if (sign(a) < 0) a += 2 * pi;
  if (sign(a - 2 * pi) >= 0) a -= 2 * pi;
  return a;
}

double angle(point a, point b) {
  return fix(atan2(b.y - a.y, b.x - a.x));
}

point rotate(point a, point b, double alpha) {
  double s, c, x, y;
  a.x -= b.x;
  a.y -= b.y;
  c = cos(alpha);
  s = sin(alpha);
  x = a.x * c - a.y * s;
  y = a.x * s + a.y * c;
  a.x = x + b.x;
  a.y = y + b.y;
  return a;
}

double area_heron(double a, double b, double c) {
  double s = (a + b + c) / 2.0;
  if (a > s || b > s || c > s) return -1;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double area_triangle(point a, point b, point c) {
  return fabs(a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y) / 2;
}

double area_polygon(point a[], int n) {
  double area = 0;
  for (int j = 0, i = n - 1; j < n; i = j++)
    area += a[i].x * a[j].y - a[i].y * a[j].x;
  return area / 2;
}

point centroid(point a[], int n) {
  double area = 0;
  point c;
  
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    area += a[i].x * a[j].y - a[i].y * a[j].x;
    c.x += (a[i].x + a[j].x) * (a[i].x * a[j].y - a[i].y * a[j].x);
    c.y += (a[i].y + a[j].y) * (a[i].x * a[j].y - a[i].y * a[j].x);
  }
  area = fabs(area) / 2;
  c.x /= 6 * area;
  c.y /= 6 * area;
  return c;
}

/* ---------- convex hull ---------- */

point __o;

bool acmp(point a, point b) {
  int c = sign(cross(__o, a, b));
  return c > 0 || !c && dist(a, __o) < dist(b, __o);
}

/* find convex hull of p[n] in place
 * return # of points of resulting convex hull */
int find_convex(point p[], int n) {
  __o = *min_element(p, p + n);
  sort(p, p + n, acmp);
  
  int top = 0;
  point *stack = (point *)malloc(sizeof(point) * n); // XXX malloc!

  for (int i = 0; i < n; i++) {
    while (top >= 2 && sign(cross(stack[top - 2], stack[top - 1], p[i])) <= 0) top--;
    stack[top++] = p[i];
  }
  copy(stack, stack + top, p);
  free(stack);
  return top;
}

/* ---------- rotate calipers ---------- */

double shadow_length(double alpha, point a, point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double c = cos(alpha);
  double s = sin(alpha);
  return fabs(dx * c + dy * s);
}

/* min area & min peri rectangle covering, using rotate calipers */
void rotate_calipers(point ps[], int n, double &area, double &peri)  {
  area = peri = inf;
  n = find_convex(ps, n);
  ps[n] = ps[0];

  point *q[4] = { NULL, NULL, NULL, NULL };
  for (int i = 0; i < n; i++) {
    point *p = &ps[i];
    if (!q[0] || q[0]->y > p->y || q[0]->y == p->y && q[0]->x > p->x) q[0] = p;
    if (!q[1] || q[1]->x < p->x || q[1]->x == p->x && q[1]->y > p->y) q[1] = p;
    if (!q[2] || q[2]->y < p->y || q[2]->y == p->y && q[2]->x < p->x) q[2] = p;
    if (!q[3] || q[3]->x > p->x || q[3]->x == p->x && q[3]->y < p->y) q[3] = p;
  }

  double alpha = 0;
  for (int k = 0; k < n + 5; k++) {
    int bi = -1;
    double gap_min = inf;
    for (int i = 0; i < 4; i++) {
      double gap = fix(angle(q[i][0], q[i][1]), alpha + i * pi / 2);
      if (gap < gap_min) {
        gap_min = gap;
        bi = i;
      }
    }
    if (++q[bi] == ps + n) q[bi] = ps + 0;
    alpha = fix(alpha + gap_min);

    double a = shadow_length(alpha + pi / 2, *q[0], *q[2]);
    double b = shadow_length(alpha, *q[1], *q[3]);
    area = min(area, a * b);
    peri = min(peri, a + a + b + b);
  }
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

int on_line(line l, point p) {
  return !sign(cross(l.p, l.q, p));
}

/* u, v: line */
int coinside(line u, line v) {
  return on_line(u, v.p) && on_line(u, v.q);
}

/* u, v: line segment, inclusive */
int intersected(line u, line v) {
  return !parallel(u, v) && side(u, v.p, v.q) <= 0 && side(v, u.p, u.q) <= 0;
}

/* u, v: line segment, exclusive */
int intersected_exclusive(line u, line v) {
  return !parallel(u, v) && side(u, v.p, v.q) < 0 && side(v, u.p, u.q) < 0;
}

/* intersection point */
point ip(line u, line v) {
  double n = (u.p.y - v.p.y) * (v.q.x - v.p.x) - (u.p.x - v.p.x) * (v.q.y - v.p.y);
  double d = (u.q.x - u.p.x) * (v.q.y - v.p.y) - (u.q.y - u.p.y) * (v.q.x - v.p.x);
  double r = n / d;
  return point(u.p.x + r * (u.q.x - u.p.x), u.p.y + r * (u.q.y - u.p.y));
}

/* if P on the line segment l, inclusive */
int on_lineseg(line l, point P) {
  return on_line(l, P) && sign(dot(P, l.p, l.q)) <= 0;
}

/* if P on the line segment l, exclusive */
int on_lineseg_exclusive(line l, point P) {
  return on_line(l, P) && sign(dot(P, l.p, l.q)) < 0;
}

double dist_line_point(line l, point a) {
  return fabs(cross(l.p, l.q, a)) / dist(l.p, l.q);
}

double dist_lineseg_point(line l, point a) {
  if (on_lineseg(l, a)) return 0;
  if (on_line(l, a) || !sharp(l.p, a, l.q)) 
    return min(dist(l.p, a), dist(l.q, a));
  return dist_line_point(l, a);
}

/* u: line segment, ab: ray, p is the resulting intersection point */
int intersected_lineseg_ray(line u, line v, point &p) {
  if (parallel(u, v)) return 0;
  p = ip(u, v);
  return on_lineseg(u, p) && (on_lineseg(v, p) || on_lineseg(line(v.p, p), v.q));
}

/* if point a inside polygon p[n] */
int inside_polygon(point p[], int n, point a) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    if (on_lineseg(line(p[i], p[j]), a)) return 0;
    double angle = acos(dot(a, p[i], p[j]) / dist(a, p[i]) / dist(a, p[j]));
    sum += sign(cross(a, p[i], p[j])) * angle;
  }
  return sign(sum);
}

/* if lineseg l strickly inside polygon p[n] */
int lineseg_inside_polygon(point p[], int n, line l) {
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    line l1(p[i], p[j]);
    if (on_lineseg_exclusive(l, p[i])) return 0;
    if (intersected_exclusive(l, l1)) return 0;
  }
  return inside_polygon(p, n, mp(l.p, l.q));
}

/* if lineseg l intersect convex polygon p[n] */
int intersect_convex_lineseg(point p[], int n, line l) {
  if (n < 3) return 0;
  
  point q[4]; int k = 0;
  q[k++] = l.p;
  q[k++] = l.q;
  for (int i = 0; i < n; i++) {
    if (on_lineseg(l, p[i])) {
      q[k++] = p[i];
    } else {
      int j = (i + 1) % n;
      line a(p[i], p[j]);
      point X = ip(a, l);
      if (on_lineseg(l, X) && on_lineseg(a, X)) q[k++] = X;
    }
  }
  
  sort(q, q + k);
  for (int i = 0; i + 1 < k; i++) {
    if (inside_polygon(p, n, mp(q[i], q[i + 1]))) return 1;
  }
  return 0;
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
int in1(line u, line v) {
  return !parallel(u, v) && side(u, v.p, v.q) <= 0 && side(v, u.p, u.q) < 0;
}

int myround(double x) {
  int i = (int)x;
  int k = i;
  for (int j = i - 2; j <= i + 2; j++)
    if (fabs(x - j) < fabs(x - k))
      k = j;
  return k;
}

const int N = 32;

int n, m, d;
int si, sj, ln;
char map[N][N];
point st;
line ls[N * N * 4];

int solve(point u, point v) {
  line l(u, v), *lz = NULL;
  point best;
  double dmin = inf;
  if (!sign(cross(u, v, st)) && sign(dot(u, v, st)) > 0)
    dmin = dist(best = st, u);
  for (int i = 0; i < ln; i++) {
    if (in1(l, ls[i])) {
      point p = ip(l, ls[i]);
      if (dmin > dist(p, u)) {
        dmin = dist(p, u);
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
      return solve(best, v);
    } else if (zs == 2) {
      if (z1 && z2) {
        v.x = 2 * best.x - v.x;
        return solve(best, v); // reflect
      } else if (z2 && z3) {
        v.y = 2 * best.y - v.y; // reflect
        return solve(best, v); // through
      } else if (z1 && z3) {
        return solve(best, v); // through
      } else assert(0);
    } else if (zs == 1) {
      if (z2) {
        return 0;
      } else {
        return solve(best, v); // through
      }
    }
  } else {
    v = mirror(*lz, v);
    return solve(best, v);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    fprintf(stderr, "case %d\n", t);
    scanf("%d %d %d", &n, &m, &d);
    ln = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", map[i]);
      for (int j = 0; j < m; j++)
        if (map[i][j] == '#') {
          point a(i + i + 0, j + j + 0);
          point b(i + i + 2, j + j + 0);
          point c(i + i + 2, j + j + 2);
          point d(i + i + 0, j + j + 2);
          ls[ln++] = line(a, b);
          ls[ln++] = line(b, c);
          ls[ln++] = line(c, d);
          ls[ln++] = line(d, a);
        } else if (map[i][j] == 'X') {
          si = i;
          sj = j;
          st = point(i + i + 1, j + j + 1);
        }
    }
    int ans = 0;
    for (int i = -d; i < n + d; i++)
      for (int j = -d; j < m + d; j++) if (sqri(si - i) + sqri(sj - j) <= sqri(d) && (si != i || sj != j)) {
        int s = solve(st, point(i + i + 1, j + j + 1));
//        if (s) printf("%d,%d\n", i, j);
        ans += s;
      }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
