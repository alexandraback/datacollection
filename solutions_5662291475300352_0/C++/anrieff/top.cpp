#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

struct vec2 {
	double x, y;
	vec2(){}
	vec2(double _x, double _y) { x = _x; y = _y; }
};
inline vec2 operator + (const vec2& a, const vec2& b) { return vec2(a.x + b.x, a.y + b.y); }
inline vec2 operator - (const vec2& a, const vec2& b) { return vec2(a.x - b.x, a.y - b.y); }
inline vec2 operator * (const vec2& a, double m) { return vec2(a.x * m, a.y * m); }
inline double lengthSqr(const vec2& a) { return a.x * a.x + a.y * a.y; }
inline double length(const vec2& a) { return sqrt(a.x * a.x + a.y * a.y); }
inline vec2 normalize(const vec2& a) { return a * (1.0 / length(a)); }

bool crossLines(const vec2& a, const vec2& b, const vec2& c, const vec2& d, double &p, double& q)
{
	vec2 u = b - a;
	vec2 v = c - d;
	vec2 h = c - a;
	double Dcr = u.x * v.y - u.y * v.x;
	if (fabs(Dcr) < 1e-12) return false;
	double rDcr = 1.0 / Dcr;
	p = (h.x * v.y - h.y * v.x) * rDcr;
	q = (u.x * h.y - u.y * h.x) * rDcr;
	return true;
}


struct Hiker {
	int num, startDeg, fastest;
};

vector<pair<vec2, vec2> > lines;
int n;

Hiker h[10];

int solve()
{
	lines.clear();
	
	double maxy = 1;
	FOR(i, n) FOR(j, h[i].num) {
		vec2 start(h[i].startDeg / 360.0, 0);
		FOR(k, 10) {
			if (k) start.x = 0;
			double s = (h[i].fastest + j);
			vec2 end(1.0, start.y + (1 - start.x) * s);
			lines.push_back(make_pair(start, end));
			start = end;
			maxy = max(maxy, end.y);
		}
	}
	
	int minCrosses = 999999999;
	//
	FOR(tries, 10000) {
		double endY = drand48() * maxy;
		if (tries < 360)
			endY = tries+ 0.1;
		vector<double> x, y;
		x.push_back(0);
		x.push_back(1);
		y.push_back(0);
		y.push_back(endY);
		int tt = rand() % 10;
		while (tt--) {
			x.push_back(drand48());
			y.push_back(drand48() * endY);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		//
		int crosses = 0;
		FOR(i, (int) x.size() - 1) {
			REP(j, lines) {
				double p, q;
				if (crossLines(vec2(x[i], y[i]), vec2(x[i+1], y[i+1]), lines[j].first, lines[j].second, p, q) && p > -1e-6 && p < 1 + 1e-6)
					crosses++;
			}
		}
		minCrosses = min(minCrosses, crosses);
	}
	return minCrosses;
}

int main(void)
{
	int T;
// 	freopen("/home/vesko/gcj/c.in", "rt", stdin);
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);
		FOR(i, n) {
			scanf("%d%d%d", &h[i].startDeg, &h[i].num, &h[i].fastest);
		}
		printf("Case #%d: %d\n", tc, solve());
	}

	return 0;
}
