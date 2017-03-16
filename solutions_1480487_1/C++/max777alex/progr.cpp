#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <sstream>
#include <deque>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
template<class T> inline T sqr(T a) {return a * a;}
#define INF 123456789
#define MOD 1000000007
#define PRIME 1103
#define TEST "A-large"
#define eps 1e-9

int n, sum;
vector<int> a;
bool f(double p, int x, double val)
{
	for(int i = 0; i < n; ++i)
	{
		if(i == x || a[i] > val) continue;
		double dp = (val - a[i] ) / (sum + .0);
		if(p - dp < 0) return 1;
		p -= dp;
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen(TEST ".in", "r", stdin);
	freopen(TEST ".out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; ++test)
	{
		scanf("%d", &n);
		sum = 0;
		a.resize(n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		vector<double> res(n, .0);
		for(int i = 0; i < n; ++i)
		{
			double l = .0, r = 1., ans = 1.;
			for(int it = 0; it < 64; ++it)
			{
				double mid = (l + r) / 2;
				bool b = f(1. - mid, i, a[i] + mid * sum);
				if(b)
				{
					r = mid;
					ans = mid;
					continue;
				}
				l = mid;
			}
			res[i] = ans;
		}
		printf("Case #%d: ", test);
		for(int i = 0; i < n; ++i)
			printf("%.6f ", 100. * res[i]);
		cout << endl;
	}
	return 0;
}