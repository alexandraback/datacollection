#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <set>
#include <queue>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

typedef long long lli;
typedef long li;

const lli INFLL = LONG_LONG_MAX;
const li INF = LONG_MAX, H = 251, W = 251;

const li dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

struct Field
{
	char a[H][W];
	bool u[H][W];
	li h, w, m;

	Field (li h, li w) : h(h), w(w)
	{
		a[h - 1][w - 1] = 'c';
	}

	bool IsMine (li y, li x)
	{
		return InBounds(x, y) && a[y][x] == '*';
	}

	bool IsDot (li y, li x)
	{
		return InBounds(x, y) && a[y][x] == '.';
	}

	bool PutMine (li y, li x)
	{
		if (a[y][x] == '.')
		{
			a[y][x] = '*';
			return 1;
		}
		return 0;
	}

	li MinesAround (li y, li x)
	{
		li res = 0;
		for (li di = 0; di < 8; ++ di)
		{
			li nx = x + dir[di][0],
			ny = y + dir[di][1];
			res += IsMine(ny, nx);
		}
		return res;
	}

	bool InBounds (li x, li y)
	{
		return x >= 0 && x < w && y >= 0 && y < h;
	}

	li Reval ()
	{
		for (li y = 0; y < h; ++ y)
		{
			for (li x = 0; x < w; ++ x)
			{
				u[y][x] = 0;
			}
		}

		return Reval(h - 1, w - 1);
	}

	li Reval (li y, li x)
	{
		if (!InBounds(x, y) || a[y][x] == '*' || u[y][x]) return 0;
		u[y][x] = 1;
		li res = 1;
		if (!MinesAround(y, x))
		{
			for (li di = 0; di < 8; ++ di)
			{
				li nx = x + dir[di][0],
				ny = y + dir[di][1];
				res += Reval(ny, nx);
			}
		}
		return res;
	}

	void Print ()
	{
		for (li y = 0; y < h; ++ y)
		{
			for (li x = 0; x < w; ++ x)
			{
				putchar(a[y][x]);
			}
			putchar('\n');
		}
	}
};

void solve ()
{
	srand(time(0));

	li tests;
	scanf("%ld", &tests);
	//tests = 1;

	for (li t = 1; t <= tests; ++ t)
	{
		li h, w, m;
		scanf("%ld %ld %ld", &h, &w, &m);

		li dots = w * h - m;

		vector <char> f;
		for (li i = 0; i < m; ++ i) f.push_back('*');
		for (li i = h * w - m; i > 1; -- i) f.push_back('.');
		//for (li i = 0, sz = f.size(); i < sz; ++ i) printf("%c", f[i]);

		Field field = Field(h, w);
		bool ok = 0;
		do
		{
			for (li i = 0, sz = f.size(); i < sz; ++ i)
			{
				field.a[i / w][i % w] = f[i];
			}
			//printf("----\n");
			//field.Print();
			if (field.Reval() == dots)
			{
				ok = 1;
				break;
			}
		}
		while (next_permutation(f.begin(), f.end()));

		printf("Case #%ld:\n", t);
		if (ok)
		{
			field.Print();
		}
		else
		{
			printf("Impossible\n");
		}
	}
}

void init ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{
	//init();
	solve();
	return 0;
}
