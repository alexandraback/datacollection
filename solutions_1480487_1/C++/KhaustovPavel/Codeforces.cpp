#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>

#pragma comment(linker, "/STACK:64000000") 

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pii64;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define xn _dsfhsdfsj
#define yn _dthsdfshj

#define toMod 1000000007

int nt;
int n;
int a[1 << 10];
int tn;
double SUM;

inline void init()
{
	scanf("%d", &n);
	SUM = 0.0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		SUM += (double)a[i];
	}
}

inline int check(int ind, double val)
{
	double X = 1.0 - val;
	double Y = SUM * val + (double)a[ind];
	for (int i = 0; i < n; ++i)
	{
		if (i == ind) continue;
		if (a[i] > Y) continue;
		double Z = (Y - (double)a[i]) / SUM;
		X -= Z;
		if (X < 0) return 0;
	}
	return 1;
}

inline double solve(int ind)
{
	double l = 0.0, r = 1.0;
	for (int it = 0; it < 80; ++it)
	{
		double mid = (l + r) / 2.0;
		if (check(ind, mid))
			l = mid;
		else
			r = mid;
	}
	return (l + r) / 2.0;
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	tn = 0;
	scanf("%d", &nt);
	for (;nt--;)
	{
		init();

		++tn;
		printf("Case #%d:", tn);
		for (int i = 0; i < n; ++i)
		{
			printf(" %.11lf", 100.0 * solve(i));
		}
		printf("\n");
	}

	return 0;
}