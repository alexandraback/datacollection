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

const long long MOD = 1000003;
const int INF = 1000000000;
const int MAXN = 200005;
const double EPS = 1e-6;
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

int main()
{
	//cin.sync_with_stdio(0);
	mt19937 mt_rand(time(NULL));
	#ifdef MYDEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#else
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
	#endif

	int CASE;
	scanf("%d\n", &CASE);
	for (int T = 1; T <= CASE; ++T)
	{
		int n, mx = -1, p[1010];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &p[i]);
			mx = max(mx, p[i]);
		}
		int ans = 10000010;
		for (int i = 1; i <= mx; ++i)
		{
			int cnt = i;
			for (int j = 0; j < n; ++j)
			{
				int d = max(0, p[j] - i);
				cnt += (d + i - 1)/i;
			}
			ans = min(ans, cnt);
		}
		printf("Case #%d: %d\n", T, ans);
	}

	my_return(0);
}
