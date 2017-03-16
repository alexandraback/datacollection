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

int tc, r, c, m;
int f[50][50];

void fill()
{
	int t = m;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (t > 0) f[i][j] = 1;
			else f[i][j] = 0;
			t--;
			if (i == r - 1 && j == c - 1) f[i][j] = 2;
		}
	}
}

void fill_wo(int h, int w)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (r - i - 1 < h && c - j - 1 < w) f[i][j] = 0;
			else f[i][j] = 1;
			if (i == r - 1 && j == c - 1) f[i][j] = 2;
		}
	}
}

void print()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (f[i][j] == 1) cout << "*";
			else if (f[i][j] == 2) cout << "c";
			else cout << ".";
		}
		cout << endl;
	}
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
		for (int cs = 1; cs <= tc; cs++)
		{
			cin >> r >> c >> m;
			cout << "Case #" << cs << ":\n";
			if (r == 1)
			{
				cout << "c";
				for (int i = 1; i < c; i++)
				{
					if (c - i - 1 < m) cout << "*";
					else cout << ".";
				}
				cout << endl;
				continue;
			}
			if (c == 1)
			{
				cout << "c\n";
				for (int i = 1; i < r; i++)
				{
					if (r - i - 1 < m) cout << "*\n";
					else cout << ".\n";
				}
				continue;
			}
			int ost = r * c - m;
			if (ost == 2 || ost == 3 || ost == 5)
			{
				cout << "Impossible\n";
				continue;
			}
			if (c == 2 || ost == 1)
			{
				if (m % 2 && ost != 1)
				{
					cout << "Impossible\n";
					continue;
				}
				fill();
				print();
				continue;
			}
			if (r == 2)
			{
				if (m % 2)
				{
					cout << "Impossible\n";
					continue;
				}
				for (int i = 0; i < c; i++)
				{
					f[0][i] = f[1][i] = (i < (m / 2));
				}
				f[0][c - 1] = 2;
				print();
				continue;
			}
			if (ost > c * 2 + 1)
			{
				if (m % r == c - 1) m--;
				fill();
				f[r - 1][c - 1] = 1;
				f[r - 1][c - 3] = 2;
				print();
				continue;
			}
			for (int i = 2; i < ost; i++)
			{
				if (ost % i == 0)
				{
					fill_wo(min(i, ost / i), max(i, ost / i));
					print();
					goto HELL; //fuck, i've used it :(
				}
			}
			if ((ost + 1) % 3 == 0)
			{
				fill_wo(3, (ost + 1) / 3);
				f[r - 1][c - 1] = 1;
				if (f[r - 1][c - 3] == 1) cout << "AAAAAAA";
				f[r - 1][c - 3] = 2;
				print();
				continue;
			}

			if ((ost + 2) % 3 == 0 && ost != 7)
			{
				fill_wo(3, (ost + 2) / 3);
				f[r - 1][c - 1] = 1;
				f[r - 1][c - 2] = 1;
				if (f[r - 1][c - 4] == 1) cout << "AAAAAAA";
				f[r - 1][c - 4] = 2;
				print();
				continue;
			}
			cout << "Impossible\n";

HELL:		continue;
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