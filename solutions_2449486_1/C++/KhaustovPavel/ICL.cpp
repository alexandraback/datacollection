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
int n, m;
int a[1 << 7][1 << 7];

inline void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
}

inline int check(int x, int y)
{
	int ok = 1;
	for (int i = 0; i < m; ++i)
	{
		if (a[x][i] > a[x][y])
		{
			ok = 0;
			break;
		}
	}
	if (ok) return 1;
	ok = 1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i][y] > a[x][y])
		{
			ok = 0;
			break;
		}
	}
	return ok;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	scanf("%d", &nt);
	++nt;
	for (int tn = 1; tn < nt; ++tn)
	{
		init();
		int ok = 1;
		for (int i = 0; i < n; ++i)
		{
			if (!ok) break;
			for (int j = 0; j < m; ++j)
			{
				if (check(i, j)) continue;
				ok = 0;
				break;
			}
		}
		if (ok)
			printf("Case #%d: YES\n", tn);
		else
			printf("Case #%d: NO\n", tn);
	}

    return 0;
}