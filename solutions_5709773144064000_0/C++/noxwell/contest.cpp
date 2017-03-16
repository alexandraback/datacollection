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

int tc;

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
		double c, f, x;
		double ans, tm, er;
		cout.precision(7);
		cout << fixed;
		for (int cs = 1; cs <= tc; cs++)
		{
			cin >> c >> f >> x;
			ans = x / 2.0;
			tm = 0;
			er = 2;
			while (tm < ans)
			{
				tm += c / er;
				er += f;
				ans = min(ans, tm + x / er);
			}
			cout << "Case #" << cs << ": " << ans << endl;
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