#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int64,int64> pii64;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;

int nt;
int64 L, R;
int m;
int64 a[1 << 10];

inline int isPal(int64 x)
{
	int n = 0;
	int a[15];
	while (x)
	{
		a[n++] = (int)(x % 10);
		x /= 10;
	}
	for (int i = 0; (i << 1) < n; ++i)
		if (a[i] != a[n - i - 1]) return 0;
	return 1;
}

inline void init()
{
	cin >> L >> R;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	m = 0;
	for (int64 x = 1; x <= 10000000LL; ++x)
	{
		if (!isPal(x)) continue;
		if (!isPal(x * x)) continue;
		a[m++] = x * x;
	}

	cin >> nt;
	++nt;
	for (int tn = 1; tn < nt; ++tn)
	{
		init();
		int res = 0;
		for (int i = 0; i < m; ++i)
			if (a[i] >= L && a[i] <= R) ++res;
		printf("Case #%d: %d\n", tn, res);
	}

    return 0;
}