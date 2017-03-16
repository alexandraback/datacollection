/*
ID: eoart2
PROG: transform
LANG: C++
*/
//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:134217728")
#include <cstdio>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>
#include <cassert>
#include <random>

const long long MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 200005;
const double EPS = 1e-10;
const int HASH_POW = 7;
const double PI = acos(-1.0);

using namespace std;

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
	exit(code);
}

int d[500010], h[500010], m[500010];

int main()
{
	//cin.sync_with_stdio(0);
	mt19937 mt_rand(time(NULL));
	#ifdef MYDEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#else
	freopen("C-small-1-attempt0.in", "rt", stdin);
	freopen("C-small-1-attempt0.out", "wt", stdout);
	#endif

	int CASE;
	scanf("%d", &CASE);
	for (int t = 1; t <= CASE; ++t)
	{
		int n, ans;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d %d %d", &d[i], &h[i], &m[i]);

		if (n == 1)
			ans = 0;
		else
		{
			if (d[0] > d[1])
			{
				swap(d[0], d[1]);
				swap(h[0], h[1]);
				swap(m[0], m[1]);
			}
			double t1 = (360.0 - d[0])/360.0*m[0];
			double t2 = (720.0 - d[1])/720.0*m[1];
			if (t1 + EPS < t2)
				ans = 0;
			else
				ans = 1;
		}
		printf("Case #%d: %d\n", t, ans);
	}

	my_return(0);
}