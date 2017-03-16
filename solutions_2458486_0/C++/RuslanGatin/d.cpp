#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/stack:256000000")

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <map>
#include <memory.h>
#include <cassert>
#include <ctime>

using namespace std;

#define fo(a,b,c) for (int a = (b); a < (c); a++)
#define fr(a,b) fo(a, 0, (b))
#define fi(n) fr(i, (n))
#define fj(n) fr(j, (n))
#define fk(n) fr(k, (n))
#define fd(a,b,c) for (int a = (b); a >= (c); a--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define _(a,b) memset((a), (b), sizeof(a))
#define __(a) memset((a), 0, sizeof(a))
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long lint;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> pii;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("d-small.in", "r", stdin);
	freopen("d-small.out", "w", stdout);
}

void panic(bool expression = false)
{
	if (!expression)
	{
		cerr << "PANIC!" << endl;
		assert(false);
	}
}

int dp[1 << 20], n, keysCount, startKeys[55], color[25];
vector<int> keys[25];

multiset<int> getKeys(int mask)
{
	multiset<int> se;
	fi(keysCount)
		se.insert(startKeys[i]);
	fi(n)
	{
		if ((mask >> i) & 1)
		{
			fj(sz(keys[i]))
				se.insert(keys[i][j]);
		}
	}
	fi(n)
	{
		if ((mask >> i) & 1)
			se.erase(se.find(color[i]));
	}
	return se;
}

int go(int mask)
{
	if (dp[mask] >= 0)
		return dp[mask];
	multiset<int> se = getKeys(mask);
	fi(n)
	{
		if (((mask >> i) & 1) == 0 && se.find(color[i]) != se.end() && go(mask | (1 << i)))
			return dp[mask] = 1;
	}
	return dp[mask] = 0;
}

void solve(int test_num)
{
	cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	_(dp, -1);
	scanf("%d%d", &keysCount, &n);
	fi(keysCount)
		scanf("%d", &startKeys[i]);
	fi(n)
	{
		int c;
		scanf("%d%d", &color[i], &c);
		keys[i].resize(c);
		fj(c)
			scanf("%d", &keys[i][j]);
	}
	int _2n = 1 << n;
	dp[_2n - 1] = 1;
	int cur = 0;
	vector<int> res;
	multiset<int> se;
	fi(n)
	{
		se = getKeys(cur);
		fj(n)
		{
			if (((cur >> j) & 1) == 0 && se.find(color[j]) != se.end() && go(cur | (1 << j)))
			{
				res.pb(j);
				cur |= 1 << j;
				break;
			}
		}
	}
	if (cur != _2n - 1)
		printf("IMPOSSIBLE\n");
	else
	{
		fi(sz(res))
		{
			if (i)
				printf(" ");
			printf("%d", res[i] + 1);
		}
		printf("\n");
	}
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
		solve(i + 1);
	return 0;
}