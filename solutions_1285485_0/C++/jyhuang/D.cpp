#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define	EPS	1e-6

struct point {
	double x, y;
	point(double x = 0, double y = 0) { this->x = x, this->y = y; }
	bool operator<(const point &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

int gcd(int a, int b)
{
	return a ? gcd(b % a, a) : b;
}

double dist(const point &a, const point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(int argc, char *argv[])
{
	static char m[50][50];

	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		int h, w, d;
		cin >> h >> w >> d;
		point o;
		for (int i = 0; i < h; i++) {
			cin >> m[i];
			for (int j = 0; j < w; j++)
				if (m[i][j] == 'X')
					o.x = i + 0.5, o.y = j + 0.5;
		}
		
		// cout << o.x << ", " << o.y << endl;
		int ans = 0;
		set<point> s;
		set<pair<int, int> > g;
		queue<point> q;
		q.push(o);
		s.insert(o);
		
		while (!q.empty()) {
			point p = q.front();
			q.pop();
			vector<point> a;
			a.push_back(point(p.x, 2 - p.y));
			a.push_back(point(p.x, 2 * (w - 1) - p.y));
			a.push_back(point(2  - p.x, p.y));
			a.push_back(point(2 * (h - 1) - p.x, p.y));
			for (int i = 0; i < a.size(); i++) {
				double l = dist(a[i], o);
				if (l > (double) d + EPS) continue;
				if (s.count(a[i]) > 0) continue;
				int dx = a[i].x - o.x, dy = a[i].y - o.y;
				int dg = gcd(abs(dx), abs(dy));
				dx /= dg, dy /= dg;
				if (g.count(make_pair(dx, dy)) > 0) continue;				
				s.insert(a[i]);
				q.push(a[i]);
				g.insert(make_pair(dx, dy));
			}
		}
		
		cout << "Case #" << ti << ": " << s.size() - 1 << endl;
	}

	return 0;
}
