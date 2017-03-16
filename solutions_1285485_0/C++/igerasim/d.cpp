#include <memory>
#include <iostream>
#include <algorithm>

using namespace std;

inline int sign(int n)
{
	if (n > 0) return  1;
	if (n < 0) return -1;
	return 0;
}

char d[32][32];

bool canReach(int y0, int x0, int vy, int vx)
{
	int sy = sign(vy); vy *= 2 * sy;
	int sx = sign(vx); vx *= 2 * sx;
	int y = y0, x = x0;
	int py = 1, px = 1;
	int uy = 0, ux = 0;
	while (true) {
		int dy = 1, dx = 1;
		{	int pr = vy * px - vx * py;
			if (pr < 0) dy = 0;
			if (pr > 0) dx = 0; }
		px += 2 * dx;
		py += 2 * dy;
		ux += 2 * dx;
		uy += 2 * dy;
		int y1 = y + sy * dy;
		int x1 = x + sx * dx;
		if (d[y1][x1] == '.') {
			y = y1;
			x = x1;
		}
		else if (dx == 0) sy = -sy;
		else if (dy == 0) sx = -sx;
		else { // dy == 1 && dx == 1
			if (d[y1][x] == '.' && d[y][x1] == '.')
				return false;
			if (d[y1][x] == '#' && d[y][x1] == '#') {
				sy = -sy;
				sx = -sx;
			}
			else if (d[y][x1] == '#') {
				sx = -sx;
				y = y1;
			}
			else if (d[y1][x] == '#') {
				sy = -sy;
				x = x1;
			}
		}
		if (uy == vy && ux == vx) {
			return (y == y0 && x == x0);
		}
		if (y == y0 && x == x0 && (vy * ux - vx * uy) == 0)
			return false;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int T, H, W, D, x0, y0;
	cin >> T;
	for (int t = 0; t != T; ++t) {
		cin >> H >> W >> D;
		for (int y = 0; y != H; ++y) {
			for (int x = 0; x != W; ++x) {
				cin >> d[y][x];
				if (d[y][x] == 'X') {
					d[y][x] = '.';
					y0 = y;
					x0 = x;
				}
			}
		}
		int res = 0;
		for (int y = -D; y <= D; ++y) {
			for (int x = -D; x <= D; ++x) {
				if (y == 0 && x == 0) continue;
				if (x * x + y * y > D * D) continue;
				if (canReach(y0, x0, y, x))
					++res;
			}
		}
		cout << "Case #" << (t + 1) << ": " << res << endl;
	}
	return 0;
}

