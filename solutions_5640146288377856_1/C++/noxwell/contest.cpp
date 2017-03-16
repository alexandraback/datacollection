#pragma comment(linker, "/STACK:256000000")
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
#include <complex>

#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define sq(x) ((x)*(x))
#define tmin(x,y,z) (min(min((x),(y)),(z)))
#define _MOD 1000000009LL
#define MOD(x) (((x) + 2LL * (_MOD)) % (_MOD))
#define INF ((int)(1e9))
#define LINF ((long long)(1e16))
#define EPS (1e-8)
#define PI (3.1415926535897932384626433832795)
#define y1 asdf_1
#define y0 asdf_2
#define j0 jj0
typedef unsigned long long ull;
typedef long double ldd;

using namespace std;

int r, c, w;

int ceili(int a, int b)
{
	int res = a / b;
	while (res * b < a)
		res++;
	return res;
}

int solve()
{
	return (r - 1) * (int)(c / w) + (ceili(c, w) + w - 1);
}

int main()
{
	//freopen("input.txt", "w", stdout); testgen(5, 60, 120); return 0;
	//freopen("output.txt", "w", stdout);   precalc(); /*for (int i = 20; i < 21; i++)*/ stresstest(5, 25, 120000, 1291);   return 0;

	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int ts;
	cin >> ts;
	for (int tt = 0; tt < ts; tt++)
	{
		cin >> r >> c >> w;
		cout << "Case #" << tt + 1 << ": " << solve() << endl;
	}

	return 0;
}