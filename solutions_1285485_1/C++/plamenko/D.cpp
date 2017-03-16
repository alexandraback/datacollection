#define _CRT_SECURE_NO_DEPRECATE

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <algorithm>

using namespace std;

template <typename T>
class vect2d {
public:
	T x, y;
	static T eps;
	
	vect2d(const T &x = 0, const T &y = 0) : x(x), y(y) {}
	
	bool       operator == (const vect2d<T> &v) const { return (abs(x - v.x) <= eps && abs(y - v.y) <= eps); }
	
	vect2d<T>& operator += (const vect2d<T> &v) { x += v.x; y += v.y; return (*this); }		// +=
	vect2d<T>& operator -= (const vect2d<T> &v) { x -= v.x; y -= v.y; return (*this); }		// -=
	vect2d<T>& operator *= (const vect2d<T> &v) { x *= v.x; y *= v.y; return (*this); }		// *= (element by element)
	vect2d<T>& operator /= (const vect2d<T> &v) { x /= v.x; y /= v.y; return (*this); }		// /= (element by element)
	
	vect2d<T>& operator *= (const T &t)         { x *= t; y *= t; return (*this); }			// *= (by scalar)
	vect2d<T>& operator /= (const T &t)         { x /= t; y /= t; return (*this); }			// /= (by scalar)
	
	vect2d<T>  operator +  (const vect2d<T> &v) const { return vect2d(x + v.x, y + v.y); }	// +
	vect2d<T>  operator -  (const vect2d<T> &v) const { return vect2d(x - v.x, y - v.y); }	// -
	vect2d<T>  operator -  (                  ) const { return vect2d(     -x,      -y); }	// - unary
	vect2d<T>  operator *  (const vect2d<T> &v) const { return vect2d(x * v.x, y * v.y); }	// * (element by element)
	vect2d<T>  operator /  (const vect2d<T> &v) const { return vect2d(x / v.x, y / v.y); }	// / (element by element)
	
	vect2d<T>  operator *  (const T &t)         const { return vect2d(x * t, y * t); }		// * (by scalar)
	vect2d<T>  operator /  (const T &t)         const { return vect2d(x / t, y / t); }		// / (by scalar)
	
	T          operator &  (const vect2d<T> &v) const { return       (x * v.x + y * v.y); }	// dot product
	T          operator ^  (const vect2d<T> &v) const { return       (x * v.y - y * v.x); } // cross product (v1 ^ v2 == v1.perp() & v2)
	
	T          cross       (const vect2d<T> &v1, const vect2d<T> &v2) const { return ((v1 - *this) ^ (v2 - *this)); }
	
	vect2d<T>  rot         (const vect2d<T> &r)            const { return vect2d(x * r.x - y * r.y, y * r.x + x * r.y); }
	vect2d<T>  perp        ()                              const { return vect2d(-y, x); }
	vect2d<T>  norm        (const vect2d<T> &v = vect2d()) const { T d = abs1(); return ((d > eps) ? *this / d : v); }
	
	T          abs1        ()                              const { return (sqrt(abs2())); }
	static T   abs1        (const T &x, const T &y)              { return (sqrt(abs2(x, y))); }
	T          abs2        ()                              const { return (x * x + y * y); }
	static T   abs2        (const T &x, const T &y)              { return (x * x + y * y); }
	T          diff2       ()                              const { return (x * x - y * y); }
	static T   diff2       (const T &x, const T &y)              { return (x * x - y * y); }
};
template <typename T>
T vect2d<T>::eps = 0;

typedef vect2d<double> pnt;

int gcd(int a, int b) {
	while (a != 0) { int r = b % a; b = a; a = r; }
	return (b);
}

char a[32][32];

struct beam {
	pnt p, p1, p2;
	beam(pnt p = pnt(), pnt p1 = pnt(), pnt p2 = pnt()) : p(p), p1(p1), p2(p2) {}
};

int is_point_on_line(const pnt &p, const pnt &l1, const pnt &l2, pnt &pex = pnt()) {
	pex = p;
	return (p.cross(l1, l2) == 0);
}

int is_point_proj_on_segment(const pnt &p, const pnt &a, const pnt &b) {
	pnt ab = b - a; double sab = ab.abs2();
	pnt pa = a - p; double spa = pa.abs2();
	pnt pb = b - p; double spb = pb.abs2();
	return (fabs(spa - spb) <= sab);
}

int is_segment_crossing_line(const pnt &s1, const pnt &s2, const pnt &l1, const pnt &l2, pnt &pex = pnt()) {
	pnt sn = (s2 - s1).perp(); double sc = s1 ^ s2;
	pnt ln = (l2 - l1).perp(); double lc = l1 ^ l2;
	double nc = sn ^ ln; if (fabs(nc) <= 0) return 0;
	pex = pnt(pnt(sn.y, sc) ^ pnt(ln.y, lc), pnt(sc, sn.x) ^ pnt(lc, ln.x)) / nc;
	return is_point_proj_on_segment(pex, s1, s2);
}

pnt p_crn[4] = {pnt(-1,-1), pnt(-1,+1), pnt(+1,+1), pnt(+1,-1)};
pnt p_edg[4] = {pnt(-1, 0), pnt( 0,+1), pnt(+1, 0), pnt( 0,-1)};
int exit_point(pnt p, pnt l1, pnt l2, pnt &pex) {
	pnt l = l2 - l1;
	for (int k = 0; k < 4; k++) {
		pnt pc = p + p_crn[k];
		if ((l & p_crn[k]) > 0 && is_point_on_line(pc, l1, l2, pex)) {
			return 2*k+1;
		}
	}
	for (int k = 0; k < 4; k++) {
		pnt pe1 = p + p_edg[k] - p_edg[k].perp();
		pnt pe2 = p + p_edg[k] + p_edg[k].perp();
		if ((l & p_edg[k]) > 0 && is_segment_crossing_line(pe1, pe2, l1, l2, pex)) {
			return 2*k+2;
		}
	}
	return 0;
}

void mirror(double m, double &z1, double &z2) { z1 = 2*m - z1; z2 = 2*m - z2; }
int next_beam(beam &b, double &dl) {
	int i = int(b.p.y)/2, j = int(b.p.x)/2;
	pnt pi; int ri = exit_point(b.p, b.p2, b.p1, pi);
	pnt po; int ro = exit_point(b.p, b.p1, b.p2, po);
	dl = (po - pi).abs1();
	if (!ro) return 0;
	if (ro % 2) {
		int k = (ro-1)/2;
		int di = int(p_crn[k].y), dj = int(p_crn[k].x);
		if (a[i+di][j+dj] != '#') { b.p.y+=2*di; b.p.x+=2*dj; return 1; }
		if (a[i+di][j] != '#' && a[i][j+dj] != '#') return 0;
		if (a[i+di][j] == '#' && a[i][j+dj] == '#') { swap(b.p1, b.p2); return 1; }
		if (a[i+di][j] == '#') mirror(2*i+di, b.p1.y, b.p2.y), b.p.x+=2*dj;
		if (a[i][j+dj] == '#') mirror(2*j+dj, b.p1.x, b.p2.x), b.p.y+=2*di;
	}
	else {
		int k = (ro-2)/2;
		int di = int(p_edg[k].y), dj = int(p_edg[k].x);
		if (di && a[i+di][j] != '#') { b.p.y+=2*di; return 1; }
		if (dj && a[i][j+dj] != '#') { b.p.x+=2*dj; return 1; }
		if (di && a[i+di][j] == '#') mirror(2*i+di, b.p1.y, b.p2.y);
		if (dj && a[i][j+dj] == '#') mirror(2*j+dj, b.p1.x, b.p2.x);
	}
	return 1;
}

int simulate(int i, int j, int di, int dj, int d) {
	beam b(pnt(2*j, 2*i), pnt(2*j, 2*i), pnt(2*(j+dj), 2*(i+di)));
	double l = 0, dl = 0;
	for (int k = 1; next_beam(b, dl); k++) {
		l += dl; if (l > 2*d + 1.0) return 0;                 // beam not visible anymore (+1.0 to avoid precision errors)
		if (i == int(b.p.y)/2 && j == int(b.p.x)/2 &&
		    is_point_on_line(pnt(2*j, 2*i), b.p1, b.p2)) {    // beam reached start point
			double l0 = 2*sqrt(double(di*di + dj*dj));
			int k = int(l / l0 + 0.5);                        // l must be integer multiple of l0
			if (k*k * (di*di + dj*dj) > d*d) return 0;        // beam not visible (exact check)
			return 1;
		}
	}
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int h, w, d;
		scanf("%d %d %d", &h, &w, &d);
		for (int i = 0; i < h; i++)
			scanf("%s", a[i]);
		
		int i0 = 0, j0 = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (a[i][j] == 'X') i0 = i, j0 = j;
		
		int r = 0;
		for (int di = -d; di <= +d; di++)
			for (int dj = -d; dj <= +d; dj++)
				if (gcd(abs(di), abs(dj)) == 1)
					r += simulate(i0, j0, di, dj, d);
		printf("Case #%d: %d\n", t, r);
		fflush(stdout);
	}
	
	return 0;
}
