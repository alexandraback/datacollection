#include <set>
#include <map>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstddef>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>

#define LL long long

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0 ? -x : x; }
template <typename T> T _min(T a, T b) { return a < b ? a : b; }
template <typename T> T _max(T a, T b) { return a > b ? a : b; }

using namespace std;

int a[111][111], r[111], c[111], b[111][111];

int main()
{
//*
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
//*/
	int t, n, m;
	cin>> t;
	for (int test = 1; test <= t; test++)
	{
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		cin>> n>> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin>> a[i][j];
				r[i] = _max(r[i], a[i][j]);
				c[j] = _max(c[j], a[i][j]);
			}

		bool f = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] != _min(c[j], r[i]))
					f = false;

		cout<< "Case #"<< test<< ": "<< (f ? "YES" : "NO")<< endl;
	}
	return 0;
}
