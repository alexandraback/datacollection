#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
typedef vector<string> VS;
VS plane;
const int oo = 1000000000;
typedef long long LL;
int h, w, d;
int xc, yc;
int solve(int dx, int dy)
{
	int r = max(abs(dx), 1) * max(abs(dy), 1);
	int x = xc * 2 * r + r;
	int y = yc * 2 * r + r;
	int start_x = x, start_y = y;
	LL total_x = 0, total_y = 0;
	while (1)
	{
		int f = oo;
		if (dx > 0)
			f = min(f, (r - x % r)  / dx);
		else if (dx < 0)
			f = min(f, x % r == 0 ? r / -dx : (x % r) / -dx);
		if (dy > 0)
			f = min(f, (r - y % r)  / dy);
		else if (dy < 0)
			f = min(f, y % r == 0 ? r / -dy : (y % r) / -dy);
		x += f * dx;
		y += f * dy;
		total_x += f * (LL)abs(dx);
		total_y += f * (LL)abs(dy);
		if (total_x * total_x + total_y * total_y > d * d * 4LL * r * r)
			return 0;
		if (x == start_x && y == start_y)
		{
			return 1;
		}
		assert(x % r == 0 || y % r == 0);
		if (x % (2 * r) == 0 && y % (2 * r) == 0)
		{
			int xx1 = (x + dx) / (2 * r);
			int yy1 = (y + dy) / (2 * r);
			if (plane[xx1][yy1] == '#')
			{
				int xx0 = (x - dx) / (2 * r);
				int yy0 = (y - dy) / (2 * r);
				if (plane[xx0][yy1] == '.' && plane[xx1][yy0] == '.')
				{
					return 0;
				}
				else if (plane[xx0][yy1] == '#' && plane[xx1][yy0] == '.')
				{
					dy = -dy;
				}
				else if (plane[xx0][yy1] == '.' && plane[xx1][yy0] == '#')
				{
					dx = -dx;
				}
				else if (plane[xx0][yy1] == '#' && plane[xx1][yy0] == '#')
				{
					dx = -dx;
					dy = -dy;
				}
			}
		}
		else if (x % (2 * r) == 0)
		{
			int yy = y / (2 * r);
			int xx1 = (x + dx) / (2 * r);
			if (plane[xx1][yy] == '#')
			{
				dx = -dx;
			}
		}
		else if (y % (2 * r) == 0)
		{
			int xx = x / (2 * r);
			int yy1 = (y + dy) / (2 * r);
			if (plane[xx][yy1] == '#')
			{
				dy = -dy;
			}
		}
	}
	return 0;
}
int main()
{
	int t;
	cin >> t;
	for (int tc=0; tc<t; tc++)
	{
		cin >> h >> w >> d;
		plane.resize(h);
		for (int i=0; i<h; i++)
		{
			cin >> plane[i];
		}
		for (xc=0; xc<h; xc++)
			for (yc=0; yc<w; yc++)
				if (plane[xc][yc] == 'X')
				{
					plane[xc][yc] = '.';
					goto found;
				}
		found:;
		int res = 0;
		const int R = 256;
		for (int i=-R; i<=R; i++)
			for (int j=-R; j<=R; j++)
			{
				if ((i || j) && __gcd(abs(i), abs(j)) == 1)
					res += solve(i, j);
			}
		cout << "Case #" << tc + 1 << ": " << res << endl;
	}
	return 0;
}
