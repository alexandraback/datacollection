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
char a[4][4];
int ewas;

inline void init()
{
	ewas = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			scanf("\n%c", &a[i][j]);
			if (a[i][j] == '.') ewas = 1;
		}
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	scanf("%d", &nt);
	++nt;
	for (int tn = 1; tn < nt; ++tn)
	{
		init();
		int okX = 0, okO = 0;
		for (int i = 0; i < 4; ++i)
		{
			int cntX = 0, cntO = 0, cntT = 0;
			for (int j = 0; j < 4; ++j)
			{
				if (a[i][j] == 'X') ++cntX;
				if (a[i][j] == 'O') ++cntO;
				if (a[i][j] == 'T') ++cntT;
			}
			if (cntX + cntT == 4) okX = 1;
			if (cntO + cntT == 4) okO = 1;
			cntX = 0, cntO = 0, cntT = 0;
			for (int j = 0; j < 4; ++j)
			{
				if (a[j][i] == 'X') ++cntX;
				if (a[j][i] == 'O') ++cntO;
				if (a[j][i] == 'T') ++cntT;
			}
			if (cntX + cntT == 4) okX = 1;
			if (cntO + cntT == 4) okO = 1;
		}
		int cntX = 0, cntO = 0, cntT = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (a[j][j] == 'X') ++cntX;
			if (a[j][j] == 'O') ++cntO;
			if (a[j][j] == 'T') ++cntT;
		}
		if (cntX + cntT == 4) okX = 1;
		if (cntO + cntT == 4) okO = 1;
		cntX = 0, cntO = 0, cntT = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (a[j][3 - j] == 'X') ++cntX;
			if (a[j][3 - j] == 'O') ++cntO;
			if (a[j][3 - j] == 'T') ++cntT;
		}
		if (cntX + cntT == 4) okX = 1;
		if (cntO + cntT == 4) okO = 1;
		if (okX)
		{
			printf("Case #%d: X won\n", tn);
			continue;
		}
		if (okO)
		{
			printf("Case #%d: O won\n", tn);
			continue;
		}
		if (!ewas)
		{
			printf("Case #%d: Draw\n", tn);
			continue;
		}
		printf("Case #%d: Game has not completed\n", tn);
	}

    return 0;
}