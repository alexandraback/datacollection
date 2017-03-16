#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"


LD f(LD N, LD C, LD F, LD X)
{
	LD res = 0;
	for (int x = 0; x < N; x++)
	{
		 res += C / (2 + F * x);
	}
	res += 	X / (2 + F * N);
	return res;
}
int main()
{
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin);  freopen("output.txt", "w", stdout);
	cout.setf(ios::fixed);
	cout.precision(12);

	int T;
	cin >> T;
	LD C, F, X;
	for (int q = 0; q < T; q++)
	{
		cin >> C >> F >> X;
		int l = 0, r = 3000000;
		while (r - l > 2)
		{
			int m1 = l + (r - l) / 3;
			int m2 = r - (r - l) / 3;
			if (f(m1, C, F, X) < f(m2, C, F, X))
			{
				r = m2;
			}
			else
				l = m1;
		}
		LD res = LD(inf) * inf;
		for (int i = l; i <= r; i++)
		{
			res = min(res, f(i, C, F, X));
		}
		if (r == 3000000)
			assert(false);
		cout << "Case #" << q + 1 << ": " << res << endl;

	}
    return 0;
}
/*******************************************
*******************************************/
