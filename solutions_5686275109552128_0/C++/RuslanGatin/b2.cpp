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
#undef NDEBUG
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
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	//freopen("-large.in", "r", stdin);
	//freopen("-large.out", "w", stdout);
}

const int maxn = 1005;

int n;
int a[maxn];
int dp[maxn][maxn];

void read()
{
	n = ni();
	fi(n)
		a[i] = ni();
}

int getDp(int n, int mn)
{
	if (n <= mn)
		return 0;
	if (dp[mn][n] >= 0)
		return dp[mn][n];
	int &ret = dp[mn][n];
	ret = n - mn;
	fj(n) if (j)
	{
		ret = min(ret, getDp(j, mn) + getDp(n - j, mn) + 1);
	}
	return ret;
}

int getF(int bound)
{
	int ret = 0;
	fi(n)
		ret += getDp(a[i], bound);
	return ret + bound;
}

void solve(int test_num)
{
	cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	int res = *max_element(a, a + n);
	fd(i, res - 1, 1)
		res = min(res, getF(i));
	printf("%d\n", res);
}

int main()
{
	prepare();
	_(dp, -1);
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
	{
		read();
		solve(i + 1);
	}
	return 0;
}