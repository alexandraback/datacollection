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

int n, p[1010];
bool y[1010];

bool good(int x, int y)
{
	return p[x] == y || p[y] == x;
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
	for (int id = 1; id <= CASE; ++id)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &p[i]);
		int ans = 2;
		vector <int> ord;
		for (int i = 1; i <= n; ++i)
			ord.push_back(i);
		do
		{
			memset(y, false, sizeof y);
			for (int i = 1; i < n - 1; ++i)
			{
				if (ord[i - 1] == p[ord[i]] || ord[i + 1] == p[ord[i]])
					y[i] = true;
			}
			for (int i = 2; i < n; ++i)
			{
				bool foo = true;
				if (!y[i - 1])
					break;
				if (ord[1] != p[ord[0]] && ord[i] != p[ord[0]])
					foo = false;
				if (ord[i - 1] != p[ord[i]] && ord[0] != p[ord[i]])
					foo = false;
				if (foo)
					ans = max(ans, i + 1);
			}
		} while (next_permutation(ord.begin(), ord.end()));
		printf("Case #%d: %d\n", id, ans);
	}

	my_return(0);
}
