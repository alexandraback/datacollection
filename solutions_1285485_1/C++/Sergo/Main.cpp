#define _SECURE_SCL 0

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#ifdef _DEBUG
#define	Assert(E)		do { if (!(E)) {  __asm {int 3}; } } while (false)
#else// _DEBUG
#define	Assert(E)		do { if (!(E)) {  __asm {int 3}; } } while (false)
//#define	Assert(E)		do { if (!(E)) { } } while (false)
#endif//_DEBUG

typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned __int64 QWORD;

//--------------------------------------------------------------------------------------------------
DWORD GDC(DWORD in_a, DWORD in_b) 
{
	DWORD a(in_a);
	DWORD b(in_b);
	while(b)
	{
		DWORD c = a % b;
		a = b;
		b = c;
	}
	return a;
}

//--------------------------------------------------------------------------------------------------
class TGrid
{
public:
	TGrid(int in_w, int in_h) :
		W(in_w), H(in_h), X(-1), Y(-1)
	{
		Grid.assign(H * W, 0);
	}

	bool Get(int in_x, int in_y)
	{
		Assert((in_x >= 0) && (in_x < W));
		Assert((in_y >= 0) && (in_y < H));
		return Grid[in_y * W + in_x] != 0;
	}

	static void HalfStep(
		int in_dx, int in_dy,
		int in_mx, int in_my,
		int &out_sx, int &out_sy)
	{
		if (abs(in_dx) > abs(in_dy))
		{
			out_sx = (in_mx / 2) * Sign(in_dx);
			out_sy = in_dy;
		}
		else
		{
			out_sx = in_dx;
			out_sy = (in_my / 2) * Sign(in_dy);
		}
	}

	static __int64 SqrDist(int in_x, int in_y, int in_mx, int in_my)
	{
		__int64 x = __int64(in_x * in_my);
		__int64 y = __int64(in_y * in_mx);
		return x * x + y * y;
	}

	static int Sign(int in_x)
	{
		if (in_x > 0)	return 1;
		else if (in_x < 0)	return -1;
		return 0;
	}

	static void GetCell(
		int in_x, int in_y,
		int in_mx, int in_my,
		int in_dx, int in_dy,
		int &out_cx, int &out_cy)
	{
		int ix = in_x / in_mx;
		int iy = in_y / in_my;
		bool eq_x = (ix * in_mx == in_x);
		bool eq_y = (iy * in_my == in_y);
		Assert(eq_x || eq_y);

		out_cx = ix;
		out_cy = iy;
		if (eq_x)
		{
			Assert(in_dx);
			if (in_dx > 0)	out_cx--;
		}

		if (eq_y)
		{
			Assert(in_dy);
			if (in_dy > 0)	out_cy--;
		}
	}
/*
	bool Trace(int in_dx, int in_dy)
	{
		bool res = Trace1(in_dx, in_dy);
		printf("%d %d = %d\n", in_dx, in_dy, res ? 1 : 0);
		return res;
	}
*/
	bool Trace(int in_dx, int in_dy)
	{
		Assert(in_dx || (abs(in_dy) == 1));
		Assert(in_dy || (abs(in_dx) == 1));

		int dx = in_dx;
		int dy = in_dy;
		int mx = dy ? abs(dy * 2) : 2;
		int my = dx ? abs(dx * 2) : 2;
		int xx0 = X * mx + mx / 2;
		int yy0 = Y * my + my / 2;
		int sx, sy;
		HalfStep(dx, dy, mx, my, sx, sy);

		int x = xx0 + sx;
		int y = yy0 + sy;
		int sumx = abs(sx);
		int sumy = abs(sy);

		__int64 max_d = D * mx * my;
		max_d = max_d * max_d;

		for(int iteration = 0; ; ++iteration)
		{
			__int64 dist = SqrDist(sumx, sumy, mx, my);
			if (dist > max_d)
				return false;

			int ix = x / mx;
			int iy = y / my;
			bool eq_x = (ix * mx == x);
			bool eq_y = (iy * my == y);
			Assert(eq_x || eq_y);

			int cx = ix, cy = iy;
			int nx = ix, ny = iy;
			if (eq_x)
			{
				Assert(dx);
				if (dx > 0)	cx--;
				else		nx--;
			}

			if (eq_y)
			{
				Assert(dy);
				if (dy > 0)	cy--;
				else		ny--;
			}

			if (eq_x && eq_y)
			{
				if (Get(nx, ny))
				{
					if (Get(cx, ny))
					{
						if (Get(nx, cy))
						{
							//reverse corner
							return dist * 4 <= max_d;
						}
						else
						{
							//horizontal wall
							dy = -dy;
							ny = cy;
						}
					}
					else if (Get(nx, cy))
					{
						//vertical wall
						dx = -dx;
						nx = cx;
					}
					else
					{
						//final corner
						return false;
					}
				}
			}
			else if (eq_x)
			{
				if (Get(nx, ny))
				{	//vertical wall
					dx = -dx;
					nx = cx;	ny = cy;
				}
			}
			else if (eq_y)
			{
				if (Get(nx, ny))
				{
					//horizontal wall
					dy = -dy;
					nx = cx;	ny = cy;
				}
			}

			if ((nx == X) && (ny == Y))
			{
				HalfStep(dx, dy, mx, my, sx, sy);
				if (	(xx0 == (x + sx))
					&&	(yy0 == (y + sy))	)
				{
					return SqrDist(sumx + abs(sx), sumy + abs(sy), mx, my) <= max_d;
				}
			}

			if (eq_x && eq_y)
			{
				HalfStep(dx, dy, mx, my, sx, sy);
				sx *= 2;
				sy *= 2;
			}
			else if (eq_x)
			{
				int offset = (y - iy * my);
				if (dy > 0)
				{
					offset = my - offset;
				}
				Assert((offset > 0) && (offset < my));

				if (offset <= abs(2 * in_dy))
				{
					sx = offset * Sign(dx);
					sy = offset * Sign(dy);
				}
				else
				{
					sx = mx * Sign(dx);
					sy = dy * 2;
				}
			}
			else if (eq_y)
			{
				int offset = (x - ix * mx);
				if (dx > 0)
				{
					offset = mx - offset;
				}
				Assert((offset > 0) && (offset < mx));

				if (offset <= abs(2 * in_dx))
				{
					sx = offset * Sign(dx);
					sy = offset * Sign(dy);
				}
				else
				{
					sx = dx * 2;
					sy = my * Sign(dy);
				}
			}

			x += sx;
			y += sy;
			sumx += abs(sx);
			sumy += abs(sy);

			GetCell(x, y, mx, my, dx, dy, cx, cy);
			Assert(cx == nx);
			Assert(cy == ny);
		}
	}

	int H, W;
	int D;
	int X, Y;
	vector<BYTE> Grid;
};


//--------------------------------------------------------------------------------------------------
void ProcessTask(int in_id)
{
	int h, w, d;
	cin >> h;
	cin >> w;
	cin >> d;

	cin.get();

	TGrid grid(w, h);
	grid.D = d;
	BYTE *dst = &grid.Grid[0];
	for(int y = 0; y < grid.H; ++y)
	{
		for(int x = 0; x < grid.W; ++x)
		{
			char ch = cin.get();
			if (ch == '#')
			{
				*dst = 1;
			}
			else if (ch == '.')
			{
				*dst = 0;
			}
			else if (ch == 'X')
			{
				*dst = 0;
				Assert(grid.X == -1);
				grid.X = x;
				grid.Y = y;
			}
			else
			{
				Assert(0);
			}
			++dst;
		}

		cin.get();
	}

	Assert(grid.X != -1);

	int res = 0;

	for(int dx = 1; dx <= d * 2; ++dx)
	{
		for(int dy = 1; dy < dx; ++dy)
		{
			if (GDC(DWORD(dx), DWORD(dy)) != 1) continue;

			if (grid.Trace(dx, dy))
				++res;
			if (grid.Trace(dy, dx))
				++res;
			if (grid.Trace(-dx, dy))
				++res;
			if (grid.Trace(dy, -dx))
				++res;

			if (grid.Trace(dx, -dy))
				++res;
			if (grid.Trace(-dy, dx))
				++res;
			if (grid.Trace(-dx, -dy))
				++res;
			if (grid.Trace(-dy, -dx))
				++res;
		}
	}

	if (grid.Trace(1, 1))
		++res;
	if (grid.Trace(1, -1))
		++res;
	if (grid.Trace(-1, 1))
		++res;
	if (grid.Trace(-1, -1))
		++res;

	if (grid.Trace(1, 0))
		++res;
	if (grid.Trace(0, 1))
		++res;
	if (grid.Trace(-1, 0))
		++res;
	if (grid.Trace(0, -1))
		++res;

	printf("Case #%d: %d\n", in_id + 1, res);
/*
	for(int y = 0; y < grid.H; ++y)
	{
		for(int x = 0; x < grid.W; ++x)
		{
			cout << (grid.Get(x, y) ? '#' : '.');
		}
		cout << endl;
	}
*/
}


//--------------------------------------------------------------------------------------------------
int main()
{
	int numb;
	cin >> numb;

	for(int i = 0; i < numb; ++i)
	{
		ProcessTask(i);
	}

	return 0;
}
