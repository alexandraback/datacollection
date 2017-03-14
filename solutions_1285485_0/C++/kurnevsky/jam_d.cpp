#include <iostream>
#include <math.h>

using namespace std;

bool mirror[30][30];
int h, w, x, y;

inline int sgn(int x)
{
	return abs(x) / x;
}

bool in_goal(int a, int b)
{
	int i = 0;
	int j = 0;
	double l = sqrt(static_cast<double>(a * a + b * b));
	int x1 = x, y1 = y;
	do
	{
		if (abs(((i + 0.5) / abs(a) * l) - ((j + 0.5) / abs(b) * l)) < 0.000001)
		{
			i++;
			j++;
			if (mirror[x1 + i * sgn(a)][y1 + j * sgn(b)])
			{
				if (!mirror[x1 + i * sgn(a)][y1 + (j - 1) * sgn(b)] && !mirror[x1 + (i - 1) * sgn(a)][y1 + j * sgn(b)])
					return false;
				if (mirror[x1 + i * sgn(a)][y1 + (j - 1) * sgn(b)] && mirror[x1 + (i - 1) * sgn(a)][y1 + j * sgn(b)])
				{
					x1 += (2 * i - 1) * sgn(a);
					a = -a;
					y1 += (2 * j - 1) * sgn(b);
					b = -b;
				}
				else if (mirror[x1 + i * sgn(a)][y1 + (j - 1) * sgn(b)])
				{
					x1 += (2 * i - 1) * sgn(a);
					a = -a;
				}
				else
				{
					y1 += (2 * j - 1) * sgn(b);
					b = -b;
				}
			}
		}
		else if (((i + 0.5) / abs(a) * l) < ((j + 0.5) / abs(b) * l))
		{
			i++;
			if (mirror[x1 + i * sgn(a)][y1 + j * sgn(b)])
			{
				x1 += (2 * i - 1) * sgn(a);
				a = -a;
			}
		}
		else
		{
			j++;
			if (mirror[x1 + i * sgn(a)][y1 + j * sgn(b)])
			{
				y1 += (2 * j - 1) * sgn(b);
				b = -b;
			}
		}
		if ((i < abs(a) || j < abs(b)) && (abs((i * 1.0 / abs(a) * l) - (j * 1.0 / abs(b) * l)) < 0.000001) && (x1 + i * sgn(a) == x && y1 + j * sgn(b) == y))
			return false;
	}
	while (i < abs(a) || j < abs(b));
	if (x1 + i * sgn(a) == x && y1 + j * sgn(b) == y)
		return true;
	return false;
}

void solve()
{
	int d, ans = 0;
	cin >> h >> w >> d;
	for (int j = 0; j < h; j++)
		for (int i = 0; i < w; i++)
		{
			char c;
			cin >> c;
			if (c == '.')
			{
				mirror[i][j] = false;
			}
			else if (c == '#')
			{
				mirror[i][j] = true;
			}
			else
			{
				mirror[i][j] = false;
				x = i;
				y = j;
			}
		}
	int i = 1;
	while (i * i + 1 <= d * d)
	{
		int j = 1;
		while (i * i + j * j <= d * d)
		{
			if (in_goal(i, j))
				ans++;
			if (in_goal(-i, j))
				ans++;
			if (in_goal(i, -j))
				ans++;
			if (in_goal(-i, -j))
				ans++;
			j++;
		}
		i++;
	}
	i = 1;
	while (!mirror[x + i][y])
		i++;
	if ((i - 1) * 2 + 1 <= d)
		ans++;
	i = 1;
	while (!mirror[x - i][y])
		i++;
	if ((i - 1) * 2 + 1 <= d)
		ans++;
	i = 1;
	while (!mirror[x][y + i])
		i++;
	if ((i - 1) * 2 + 1 <= d)
		ans++;
	i = 1;
	while (!mirror[x][y - i])
		i++;
	if ((i - 1) * 2 + 1 <= d)
		ans++;
	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}

