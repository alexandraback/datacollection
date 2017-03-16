#include "bind.h"
#include <math.h>
#define precise 1e-8

char grid[100][100];
int hashtable[200][200];
double o_px, o_py;
int o_x, o_y;
int h, w, number;
double d;

bool eq(double x, double y)
{
	if (abs(x - y) < precise)
		return true;
	return false;
}
double len(double x, double y)
{
	return sqrt(x * x + y * y);
}
class Vector
{
public:
	int m_x, m_y, g_x, g_y;
	double p_x, p_y;
	double current_length;
	Vector()
		: current_length(0) {}
	Vector(int a1, int a2, double a3, double a4)
		: m_x(a1), m_y(a2), g_x(a3), g_y(a4), current_length(0)
	{
		p_x = g_x + 0.5, p_y = g_y + 0.5;
	}
	bool judge()
	{
		if (g_x == o_x && g_y == o_y && eq((o_px - p_x) * m_y, (o_py - p_y) * m_x) && current_length + len(o_px - p_x, o_py - p_y) <= d + precise)
			return true;
		return false;
	}
	void move()
	{
		int n_x = 0, n_y = 0;

		int d_x = (m_x > 0) ? 1 : -1;
		int d_y = (m_y > 0) ? 1 : -1;

		double t1 = (eq(m_x, 0)) ? 1000000000 : (g_x + (m_x > 0) - p_x) / m_x;
		double t2 = (eq(m_y, 0)) ? 1000000000 : (g_y + (m_y > 0) - p_y) / m_y;
		if (eq(t1, t2))
		{
			n_x = d_x, n_y = d_y;
			p_x += t1 * m_x, p_y += t1 * m_y;
			current_length += len(m_x, m_y) * t1;
		}
		else
		if (t1 < t2)
		{
			n_x = d_x;
			p_x += t1 * m_x, p_y += t1 * m_y;
			current_length += len(m_x, m_y) * t1;
		}
		else
		{
			n_y = d_y;
			p_x += t2 * m_x, p_y += t2 * m_y;
			current_length += len(m_x, m_y) * t2;
		}

		if (n_x == 0)
		{
			if (grid[g_x][g_y + n_y] == '#')
				m_y = -m_y;
			else
				g_y += n_y;
			return;
		}
		if (n_y == 0)
		{
			if (grid[g_x + n_x][g_y] == '#')
				m_x = -m_x;
			else
				g_x += n_x;
			return;
		}

		if (grid[g_x + n_x][g_y] == '#' && grid[g_x + n_x][g_y + n_y] == '#' && grid[g_x][g_y + n_y] == '#')
		{
			m_x = -m_x;
			m_y = -m_y;
			return;
		}

		if (grid[g_x + n_x][g_y] != '#' && grid[g_x + n_x][g_y + n_y] == '#' && grid[g_x][g_y + n_y] == '#')
		{
			m_y = -m_y;
			g_x += n_x;
			return;
		}

		if (grid[g_x + n_x][g_y] == '#' && grid[g_x + n_x][g_y + n_y] == '#' && grid[g_x][g_y + n_y] != '#')
		{
			m_x = -m_x;
			g_y += n_y;
			return;
		}

		if (grid[g_x + n_x][g_y] != '#' && grid[g_x + n_x][g_y + n_y] == '#' && grid[g_x][g_y + n_y] != '#')
		{
			current_length = d + 1;
			return;
		}
		
		g_x += n_x, g_y += n_y;
	}
};

Vector v;

void calc(int n, int m)
{
	for (int t = max(abs(n), abs(m)); t >= 1; t--)
		if (n % t == 0 && m % t == 0)
		{
			n /= t, m /= t;
			break;
		}
	if (hashtable[n + 50][m + 50])
		return;
	hashtable[n + 50][m + 50] = 1;
	Vector v(n, m, o_x, o_y);
	for(v.move(); v.current_length < d + precise; v.move())
	{
		if (v.judge())
		{
			number++;
			return;
		}
	}
}

int main()
{
	bind("D-large");
	int step;
	inf >> step;
	for (int k = 0; k < step; k++)
	{
		memset(hashtable, 0, sizeof(hashtable));
		inf >> h >> w >> d;
		hashtable[50][50] = 1;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				inf >> grid[i][j];
				if (grid[i][j] == 'X')
				{
					o_x = i, o_y = j;
					o_px = o_x + 0.5, o_py = o_y + 0.5;
				}
			}
		number = 0;
		for (int i = -50; i <= 50; i++)
			for (int j = -50; j <= 50; j++)
				if (len(i, j) < d + precise)
					calc(i, j);
		ouf << "Case #" << k + 1 << ": " << number << "\n";
	}
	return 0;
}