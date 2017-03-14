#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

#define N 1000010

using namespace std;

char room[40][40];

int h, w, d;

struct Point {
	int x, y;
	
	Point (int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
	
	Point set(int _x = 0, int _y = 0) {
		x = _x, y = _y;
		return *this;
	}

	bool operator < (const Point &a) const {
		return x < a.x || x == a.x && y < a.y;
	}

	int dist2(const Point &a) const {
		return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
	}

	Point slope(const Point &a) {
		int dx = x - a.x, dy = y - a.y;
		int g = max(1, gcd(abs(dx), abs(dy)));
		return Point(dx / g, dy / g);
	}

private:
	static int gcd(int _x, int _y) {
		return _y ? gcd(_y, _x % _y): _x;
	}
}you;

int check(int x, int y, set<Point>& imageSlope, int &ans) {
	Point p(x, y);
	Point pSlope = p.slope(you);
	if(p.dist2(you) <= d * d && imageSlope.find(pSlope) == imageSlope.end()) {
		++ans;
		imageSlope.insert(pSlope);
	}
	return ans;
}

int solve() {
	int ans = 0;
	set<Point> imageSlope;
	for(int i = 0; i <= (d + 2 * you.x) / h; i += 2) {
		for(int j = 0; j <= (d + 2 * you.y) / w; j += 2) {
			for(int k = 0; k < 16; ++k) {
				int c[4];
				for(int ii = 0; ii < 4; ++ii) {
					c[ii] = ((k & (1<<ii)) ? -1: 1);
				}
				check(c[0] * i * h + c[1] * you.x, c[2] * j * w + c[3] * you.y, imageSlope, ans);
			}
		}
	}
	return ans - 1;
}

int main(int argc, char *argv[]) 
{
	freopen("D-small-attempt3.in", "r", stdin);
	freopen("D-small-attempt3.out", "w", stdout);
	int T;
	cin >> T;
	for(int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ": ";
		cin >> h >> w >> d;
		for(int i = 0; i < h; ++i) {
			cin >> room[i];
			for(int j = 1; j < w; ++j) {
				if(room[i][j] == 'X') {
					you.set((i - 1) * 2 + 1, (j - 1) * 2 + 1);
				}
			}
		}
		h = (h - 2) * 2, w = (w - 2) * 2, d = d * 2;
		int ans = solve();
		cout << ans << endl;
	}
	return 0;
}
