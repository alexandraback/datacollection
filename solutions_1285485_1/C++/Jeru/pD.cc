#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const double ep = 1e-10;
const int HORIZONTAL = 1;
const int VERTICAL = 2;

int R, C, D, sx0, sy0;
char maze[40][40];

struct Checker {
	int x0, y0, x1, y1, dx, dy;
	double traveled;

	Checker(int x0_, int y0_, int x1_, int y1_)
		: x0(x0_), y0(y0_), x1(x1_), y1(y1_),
		  dx(x1_ - x0_), dy(y1_ - y0_), traveled(0) {
	}

	// -1 for invalid.
	int Hit(double t) {
		double x = x0 + t * dx, y = y0 + t * dy;
		if (x < 0.5 - ep || x > R - 1.5 + ep
				|| y < 0.5 - ep || y > C - 1.5 + ep)
			return -1;
		int mx = (int)floor(x - 0.5 + ep), my = (int)floor(y - 0.5 + ep);
		if (fabs(mx + 0.5 - x) > ep) {
			// x misses boundary.
			int py = dy > 0 ? my + 1 : my;
			if (mx + 1 >= R || py >= C) return -1;
			if (maze[mx + 1][py] != '#') return 0;
			return my * 100 + VERTICAL;
		}
		if (fabs(my + 0.5 - y) > ep) {
			// y misses boundary.
			int px = dx > 0 ? mx + 1 : mx;
			if (px >= R || my + 1 >= C || maze[px][my + 1] != '#')
				return 0;
			return mx * 10000 + HORIZONTAL;
		}
		// (x,y) hits a corner.
		if (mx + 1 >= R || my + 1 >= C) return -1;
		if (maze[mx + !(dx > 0)][my + !(dy > 0)] == '#')  // pass through a mirror...
			return -1;
		if (maze[mx + (dx > 0)][my + (dy > 0)] != '#')  // bypassed
			return 0;
		int r = 0;
		if (maze[mx + (dx > 0)][my + !(dy > 0)] == '#')
			r |= HORIZONTAL;
		if (maze[mx + !(dx > 0)][my + (dy > 0)] == '#')
			r |= VERTICAL;
		if (r == 0)  // hit a dead corner
			return -1;
		return mx * 10000 + my * 100 + r;
	}

	bool Solve() {
		double next = 2.0, reach = 2.0;
		{  // hit itself?
			double t = dx != 0 ? (sx0 - x0) * 1.0 / dx : (sy0 - y0) * 1.0 / dy;
			if (t > traveled + ep && 
					fabs(x0 + t * dx - sx0) <= ep && fabs(y0 + t * dy - sy0) <= ep)
				reach = min(reach, t);
		}
		if (dx != 0) {
			for (int mx = 0; mx < R - 1; ++mx) {
				// mirrors at line "x = mx + 0.5"
				double t = (mx + 0.5 - x0) / dx;
				if (t >= next) continue;
				if (t <= traveled + ep) continue;
				int hit = Hit(t);
				if (hit == -1)
					reach = min(reach, t);
				else if (hit & HORIZONTAL)
					next = t;
			}
		}
		if (dy != 0) {
			for (int my = 0; my < C - 1; ++my) {
				// mirrors at line $y = my + 0.5"
				double t = (my + 0.5 - y0) / dy;
				if (t >= next) continue;
				if (t <= traveled + ep) continue;
				int hit = Hit(t);
				if (hit == -1)
					reach = min(reach, t);
				else if (hit & VERTICAL)
					next = t;
			}
		}
		if (reach < next - ep)
			return true;
		traveled = next;
		if (traveled < 1 - ep) {
			int hit = Hit(traveled);
			int mx = hit / 10000 % 100, my = hit / 100 % 100;
			if (hit & HORIZONTAL) {
				// mirrored against line "x = mx + 0.5"
				x0 = 2 * mx + 1 - x0;
				x1 = 2 * mx + 1 - x1;
				dx = x1 - x0;
			}
			if (hit & VERTICAL) {
				// mirrored against line "y = my + 0.5"
				y0 = 2 * my + 1 - y0;
				y1 = 2 * my + 1 - y1;
				dy = y1 - y0;
			}
		}
		return traveled >= 1 - ep;
	}
};

bool Check(int x0, int y0, int x1, int y1) {
	if (x0 == x1 && y0 == y1) return false;
	Checker c(x0, y0, x1, y1);
	while (!c.Solve());
	return c.x1 == x0 && c.y1 == y0;
}

void Solve(istream& in, ostream& out) {
	string line;
	in >> R >> C >> D;
	getline(in, line);
	for (int i = 0; i < R; ++i) {
		getline(in, line);
		copy(line.begin(), line.begin() + C, maze[i]);
	}
	int x0 = -1, y0 = -1;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if (maze[i][j] == 'X') {
				x0 = i;
				y0 = j;
			}
	sx0 = x0;
	sy0 = y0;
	int ans = 0;
	for (int x1 = x0 - D; x1 <= x0 + D; ++x1)
		for (int y1 = y0 - D; y1 <= y0 + D; ++y1) {
			int dx = x1 - x0, dy = y1 - y0;
			if (dx * dx + dy * dy > D * D)
				continue;
			if (Check(x0, y0, x1, y1))
				++ans;
		}
	out << ans << endl;
}

void Main2(istream& in, ostream& out) {
	int testNo;
	in >> testNo;
	string line;
	getline(in, line);
	for (int caseId = 1; caseId <= testNo; ++caseId) {
		out << "Case #" << caseId << ": ";
		Solve(in, out);
	}
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		cin.sync_with_stdio(false);
		cout.sync_with_stdio(false);
		Main2(cin, cout);
	} else {
		string s(argv[1]);
		if (s.size() >= 1 && s[s.size() - 1] == '.')
			s.erase(s.end() - 1);
		else if (s.size() >= 3 and s.substr(s.size() - 3) == ".in")
			s.erase(s.end() - 3, s.end());
		ifstream fin((s + ".in").c_str());
		ofstream fout((s + ".out").c_str());
		Main2(fin, fout);
	}
	return 0;
}
