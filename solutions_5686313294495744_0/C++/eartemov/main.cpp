//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#define TASK "C-small-attempt0"
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
const long double EPS = 1e-6;
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
	cin >> CASE;
	for (int it = 1; it <= CASE; ++it)
	{
		int n;
		string s[20], t[20];
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> s[i] >> t[i];

		int dp[1 << 16];
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < (1 << n) - 1; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i & (1 << j))
					continue;
				bool has1 = false, has2 = false;
				for (int k = 0; k < n; ++k)
				{
					if (i & (1 << k))
					{
						if (s[k] == s[j])
							has1 = true;
						if (t[k] == t[j])
							has2 = true;
					}
				}
				if (has1 && has2)
					dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + 1);
			}
		}

		cout << "Case #" << it << ": " << dp[(1 << n) - 1] << "\n";
	}

	my_return(0);
}