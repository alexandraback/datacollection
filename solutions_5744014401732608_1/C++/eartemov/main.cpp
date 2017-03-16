//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#define TASK "B-large"
#pragma comment(linker, "/STACK:536870912")
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
#include <map>
#include <string>
#include <functional>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>

const int MOD = 1000000007;
const int INF = 1000000001;
const int MAXN = 100010;
const long double EPS = 1e-8;
const int HASH_POW = 29;
const long double PI = acos(-1.0);

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
	cin.sync_with_stdio(0);
	cin.tie(0);
	mt19937 mt_rand(time(0));
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(TASK".in", "rt", stdin);
	freopen(TASK".out", "wt", stdout);
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/
#endif

	int CASE;
	scanf("%d", &CASE);
	for (int it = 1; it <= CASE; ++it)
	{
		int n;
		long long m;
		scanf("%d %lld", &n, &m);
		if (m > (1ll << (n - 2)))
			printf("Case #%d: IMPOSSIBLE\n", it);
		else
		{
			char G[51][51];
			memset(G, '0', sizeof G);
			for (int i = 1; i <= n - 1; ++i)
				for (int j = i + 1; j <= n - 1; ++j)
					G[i][j] = '1';
			if (m == (1ll << (n - 2)))
			{
				for (int i = 1; i <= n - 1; ++i)
					G[i][n] = '1';
			}
			else
			{
				for (int j = 2; j <= n - 1; ++j)
				{
					if (m & (1ll << (j - 2)))
						G[j][n] = '1';
				}
			}

			printf("Case #%d: POSSIBLE\n", it);
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
					printf("%c", G[i][j]);
				printf("\n");
			}
		}
	}

	my_return(0);
}