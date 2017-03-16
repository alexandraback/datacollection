#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n, m, D;
int nt;

template<typename T>
class Point
{
public:
	T x, y;
	Point() : x(0), y(0) {}
	Point(const T &x, const T &y) : x(x), y(y) {}
	Point(const Point<T> &p) : x(p.x), y(p.y) {}

	bool operator<(const Point<T> &p) const
	{
		return x < p.x || x == p.x && y < p.y;
	}
};

template<typename T> Point<T> operator+(const Point<T> &p1, const Point<T> &p2)	{ return Point<T>(p1.x + p2.x, p1.y + p2.y); }
template<typename T> Point<T> operator-(const Point<T> &p1, const Point<T> &p2) { return Point<T>(p1.x - p2.x, p1.y - p2.y); }
template<typename T> Point<T> operator*(const T &k, const Point<T> &p) { return Point<T>(k * p.x, k * p.y); }
template<typename T> Point<T> operator*(const Point<T> &p, const T &k) { return k * p; }
template<typename T> Point<T> operator/(const Point<T> &p, const T &k) { return Point<T>(p.x / k, p.y / k); }
template<typename T> T dot(const Point<T> &p1, const Point<T> &p2) { return p1.x * p2.x + p1.y * p2.y; }
template<typename T> T cross(const Point<T> &p1, const Point<T> &p2) { return p1.x * p2.y - p1.y * p2.x; }
template<typename T> T operator*(const Point<T> &p1, const Point<T> &p2) { return dot(p1, p2); }
template<typename T> T operator^(const Point<T> &p1, const Point<T> &p2)	{ return cross(p1, p2); }
template<typename T> T norm2(const Point<T> &p) { return p * p; }
template<typename T> T norm(const Point<T> &p) { return std::sqrt(norm2(p)); }
template<typename T> T distance2(const Point<T> &p1, const Point<T> &p2) { return norm2(p1 - p2); }
template<typename T> T distance(const Point<T> &p1, const Point<T> &p2) { return norm(p1 - p2); }
template<typename T> Point<T> rotate90(const Point<T> &p) { return Point<T>(p.y, -p.x); }
template<typename T> Point<T> rotate180(const Point<T> &p) { return Point<T>(-p.x, -p.y); }
template<typename T> Point<T> rotate270(const Point<T> &p) { return Point<T>(-p.y, p.x); }
template<typename T> Point<T> normalise(const Point<T> &p) { return p / norm(p); }


template<typename T>
class Line
{
public:
	Point<T> p1, p2;

	Line() : p1(), p2() {}
	Line(const Point<T> &p1, const Point<T> &p2) : p1(p1), p2(p2) {}
	Line(const T &x1, const T &y1, const T &x2, const T &y2) : p1(x1, y1), p2(x2, y2) {}

	Line(const Line<T> &l) : p1(l.p1), p2(l.p2) {}

	// convert to form A * x + B * y + C = 0 without normalisation
	void toABC(T &A, T &B, T &C) const
	{
		A = p1.y - p2.y;
		B = p2.x - p1.x;
		C = p1 ^ p2;
	}
};

const double eps = 1e-9;

template<typename T>
std::vector<Point<T>> intersection(const Line<T> &l1, const Line<T> &l2)
{
	T A1, B1, C1, A2, B2, C2;

	l1.toABC(A1, B1, C1);
	l2.toABC(A2, B2, C2);

	T det = A1 * B2 - A2 * B1;

	if (std::abs(det) <= eps) return std::vector<Point<T>>();

	return std::vector<Point<T>>(1, Point<T>(C2 * B1 - C1 * B2, A2 * C1 - A1 * C2) / det);
}

template<typename T> T gcd(T a, T b)
{
	a = std::abs(a);
	b = std::abs(b);
	while(a && b) if (a < b) b %= a; else a %= b;
	return a + b;
}

char s[50][50];

Point<double> you;

bool along(const Line<double> &ray, const Point<double> &p)
{
	double dx = ray.p2.x - ray.p1.x;
	if (dx > eps) return p.x - ray.p1.x > eps;
	if (dx < -eps) return p.x - ray.p1.x < -eps;
	
	double dy = ray.p2.y - ray.p1.y;
	if (dy > eps) return p.y - ray.p1.y > eps;
	if (dy < -eps) return p.y - ray.p1.y < -eps;
	
	return false;
}

template<typename T> T distance(const Point<T> &p, const Line<T> &l) { return std::abs(normalise(l.p2 - l.p1) ^ (p - l.p1)); }	

bool good(int dx, int dy, const Point<double> &o, double dist)
{
	Line<double> ray(o, Point<double>(o.x + dx, o.y + dy));
	
	Point<double> to(0, 0);
	double closest_dist = dist + 1;
	
	bool right = false;

	int i1 = max(((int)(o.x - dist) - 2), 0);
	int i2 = min(((int)(o.x + dist) + 2), n - 1);
	
	int j1 = max(((int)(o.y - dist) - 2), 0);
	int j2 = min(((int)(o.y + dist) + 2), m - 1);
	
	for(int i = i1; i <= i2; i++)
	for(int j = j1; j <= j2; j++)
	if (s[i][j] == '#')
	{
//	for(int k = 0; k < walls.size(); k++)
//	{
//		int i = walls[k].first;
//		int j = walls[k].second;
		
		if (distance(o, Point<double>(i, j)) > dist + 1.5) continue;
		
		auto ps = intersection(ray, Line<double>(i, j, i, j + 1));
		if (ps.size() > 0 && ps[0].y > j - eps && ps[0].y < j + 1 + eps && along(ray, ps[0]) && distance(o, ps[0]) < closest_dist)
		{
			closest_dist = distance(o, ps[0]);
			to = ps[0];
			right = (dy == 0);
		}
		
		ps = intersection(ray, Line<double>(i, j, i + 1, j));
		if (ps.size() > 0 && ps[0].x > i - eps && ps[0].x < i + 1 + eps && along(ray, ps[0]) && distance(o, ps[0]) < closest_dist)
		{
			closest_dist = distance(o, ps[0]);
			to = ps[0];
			right = (dx == 0);
		}
		
		ps = intersection(ray, Line<double>(i + 1, j, i + 1, j + 1));
		if (ps.size() > 0 && ps[0].y > j - eps && ps[0].y < j + 1 + eps && along(ray, ps[0]) && distance(o, ps[0]) < closest_dist)
		{
			closest_dist = distance(o, ps[0]);
			to = ps[0];
			right = (dy == 0);
		}
		
		ps = intersection(ray, Line<double>(i, j + 1, i + 1, j + 1));
		if (ps.size() > 0 && ps[0].x > i - eps && ps[0].x < i + 1 + eps && along(ray, ps[0]) && distance(o, ps[0]) < closest_dist)
		{
			closest_dist = distance(o, ps[0]);
			to = ps[0];
			right = (dx == 0);
		}		
	}
	
	if (along(ray, you) && distance(you, ray) < eps)
	{
		double d = distance(o, you);
		if (d < closest_dist)
		{
			return d < dist + eps;
		}
	}
	
	if (closest_dist > dist + eps) return false;
	
	if (right) return good(-dx, -dy, to, dist - closest_dist);
	
	assert(abs(to.x - ((int)(to.x + 0.1))) < eps || abs(to.y - ((int)(to.y + 0.1))) < eps);
	
	if (abs(to.x - ((int)(to.x + 0.1))) > eps) return good(dx, -dy, to, dist - closest_dist);
	if (abs(to.y - ((int)(to.y + 0.1))) > eps) return good(-dx, dy, to, dist - closest_dist);
	
	// hit corner
	
	int i = (int)(to.x + 0.1);
	int j = (int)(to.y + 0.1);
	
	int cnt = (s[i][j] == '#') + (s[i - 1][j - 1] == '#') + (s[i][j - 1] == '#') + (s[i - 1][j] == '#');
	assert(cnt > 0);
	
	if (s[i][j] == '#' && s[i][j - 1] == '#' && s[i - 1][j] != '#' && s[i - 1][j - 1] != '#') return good(-dx, dy, to, dist - closest_dist);
	if (s[i][j] != '#' && s[i][j - 1] != '#' && s[i - 1][j] == '#' && s[i - 1][j - 1] == '#') return good(-dx, dy, to, dist - closest_dist);

	if (s[i][j] == '#' && s[i - 1][j] == '#' && s[i][j - 1] != '#' && s[i - 1][j - 1] != '#') return good(dx, -dy, to, dist - closest_dist);
	if (s[i][j] != '#' && s[i - 1][j] != '#' && s[i][j - 1] == '#' && s[i - 1][j - 1] == '#') return good(dx, -dy, to, dist - closest_dist);
	
	if (cnt == 2) return good(dx, dy, to, dist - closest_dist);	
	
	if (cnt == 3) return good(-dx, -dy, to, dist - closest_dist);
	
	assert(cnt == 1);
	
	if (dx > 0 && dy > 0 && s[i][j] == '#') return false;
	if (dx > 0 && dy < 0 && s[i][j - 1] == '#') return false;
	if (dx < 0 && dy > 0 && s[i - 1][j] == '#') return false;
	if (dx < 0 && dy < 0 && s[i - 1][j - 1] == '#') return false;	
	
	return good(dx, dy, to, dist - closest_dist);
}

int main(int argc, char **args)
{
	int k1, k2;
	sscanf(args[1], "%d", &k1);
	sscanf(args[2], "%d", &k2);
	scanf("%d", &nt);
	
	for(int tt = 1; tt <= nt; tt++)
	{	
		if (tt >= k1 && tt <= k2) printf("Case #%d: ", tt);
		
		scanf("%d %d %d", &n, &m, &D);
		
		for(int i = 0; i < n; i++) scanf("%s", s[i]);
		
		if (tt < k1 || tt > k2) continue;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if (s[i][j] == 'X') you = Point<double>(i + 0.5, j + 0.5);
			
		
		int res = good(0, 1, you, D) + good(0, -1, you, D) + good(1, 0, you, D) + good(-1, 0, you, D);
		
		for(int dx = -101; dx <= 101; dx++)
		for(int dy = -101; dy <= 101; dy++)
		if (dx && dy)
		{
			if (gcd(dx, dy) != 1) continue;
			if (dx * dx + dy * dy > D * D) continue;
			if (good(dx, dy, you, D)) res++;			
		}
		
		
		printf("%d\n", res);
	}
	
	return 0;
}
