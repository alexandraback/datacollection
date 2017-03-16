#pragma comment(linker, "/STACK:536870912")
#define _USE_MATH_DEFINES
#define _CRT_NO_DEPRECEATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>
#include <iomanip>


#define pb push_back
#define mp make_pair
#define sq(x) ((x)*(x))
#define INF (2e9)
#define EPS (1e-8)
#define PI (3.1415926535897932384626433832795)
#define _STRESS 0
#define y1 asdf_1
#define y0 asdf_2

using namespace std;

#define MOD(x) ((x) % (123456791LL))
#define BASE (1103LL)

int tc, r, c, m, ax, ay;
bool f[5][5];
bool u[5][5];
int fi = 0;

int dfs(int x, int y)
{
	if (f[x][y] || u[x][y]) return 0;
	u[x][y] = 1;
	int ctr = 0, res = 1;
	for (int i = -1; i <= 1; i++)
	for (int j = -1; j <= 1; j++)
	{
		if (!i && !j || x + i < 0 || x + i >= r || y + j < 0 || y + j >= c) continue;
		ctr += f[x + i][y + j];
	}
	if (!ctr)
	{
		for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if (!i && !j || x + i < 0 || x + i >= r || y + j < 0 || y + j >= c) continue;
			res += dfs(x + i, y + j);
		}
	}
	return res;
}

bool check()
{
	int ctr = 0;
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
	{
		if (f[i][j]) ctr++;
	}
	if (ctr != m) return false;
	for (ax = 0; ax < r; ax++)
	for (ay = 0; ay < c; ay++)
	{
		memset(u, 0, sizeof u);
		int res = dfs(ax, ay);
		if (res + ctr == r * c) return true;
	}
	return false;
}

bool next_field()
{
	fi++;
	if (fi == (1 << (r * c))) return 0;
	int res = fi;
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
	{
		f[i][j] = !(res & 1);
		res >>= 1;
	}
	return 1;
}

class Solver
{
public:
	void init()
	{
#ifdef _MY_DEBUG
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
#else
		//freopen("ragnarok.in","rt", stdin);
		//freopen("ragnarok.out","wt", stdout);
#endif
	}

	int solve()
	{
		cin >> tc;
		bool flag = 0;
		for (int cs = 1; cs <= tc; cs++)
		{
			cin >> r >> c >> m;
			fi = 0;
			memset(f, 0, sizeof f);
			flag = 0;
			cout << "Case #" << cs << ":\n";
			do
			{
				if (check())
				{
					flag = 1;
					for (int i = 0; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							if (ax == i && ay == j) cout << "c";
							else if (f[i][j]) cout << "*";
							else cout << ".";
						}
						cout << endl;
					}
					break;
				}
			} while (next_field());
			if (!flag)
				cout << "Impossible" << endl;
		}

		return 0;
	}

	void finalize()
	{

	}
};

Solver solver;

class Tester
{
public:
	void randinit()
	{
	}

	void solve_slow()
	{
	}

	void stresstest()
	{
	}
};

#if _STRESS
Tester tester;
#endif

int main()
{
#if _STRESS
	tester.stresstest();
#else
	solver.init();
	solver.solve();
	solver.finalize();
#endif
	return 0;
}