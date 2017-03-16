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

int tc, n;
double a[2000], b[2000];
bool u[2000];

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
			cin >> n;
			for (int i = 0; i < n; i++)
				cin >> a[i];
			for (int i = 0; i < n; i++)
				cin >> b[i];
			sort(a, a + n);
			sort(b, b + n);
			int ans1 = 0;
			int bt = 0;
			for (int i = n - 1; i >= 0; i--)
			{
				if (a[i + bt] > b[i]) ans1++;
				else bt++;
			}
			int ans2 = 0, ti;
			memset(u, 0, sizeof u);
			for (int i = 0; i < n; i++)
			{
				ti = -1;
				for (int j = 0; j < n; j++)
				{
					if (!u[j] && ti == -1) ti = j;
					if (!u[j] && b[j] > a[i])
					{
						ti = j;
						break;
					}
				}
				u[ti] = 1;
				if (a[i] > b[ti]) ans2++;
			}
			cout << "Case #" << cs << ": " << ans1 << " " << ans2 << endl;
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