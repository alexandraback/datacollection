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

int dp[1000010];

int main()
{
	//cin.sync_with_stdio(0);
	mt19937 mt_rand(time(NULL));
	#ifdef MYDEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#else
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
	#endif
	
	dp[1] = 1;
	for (int i = 2; i <= 1000000; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		int s = 0, r = i;
		while (r)
		{
			s = 10*s + r % 10;
			r /= 10;
		}
		int check = 0;
		r = s;
		while (r)
		{
			check = 10*check + r % 10;
			r /= 10;
		}
		if (s < i && check == i)
			dp[i] = min(dp[i], dp[s] + 1);
	}

	int CASE;
	scanf("%d", &CASE);
	for (int t = 1; t <= CASE; ++t)
	{
		long long n;
		scanf("%lld", &n);
		long long ans = 0;

		ans = dp[n];

		printf("Case #%d: %lld\n", t, ans);
	}

	my_return(0);
}