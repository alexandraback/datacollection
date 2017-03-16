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
	freopen("c-small.in", "r", stdin);
	freopen("c-small.out", "w", stdout);
	//freopen("-large.in", "r", stdin);
	//freopen("-large.out", "w", stdout);
}

int l;
lint x;
string s;
int mx[4][4] =
{
	{4, 1, 2, 3},
	{1, -4, 3, -2},
	{2, -3, -4, 1},
	{3, 2, -1, -4},
};
int used[10];

void read()
{
	l = ni();
	x = nll();
	s = ns();
}

int getCode(char c)
{
	return c - 'i' + 1;
}

int sgn(int x)
{
	return x < 0 ? -1 : 1;
}

int mul(int x, int c)
{
	return sgn(x) * mx[abs(x) & 3][c & 3];
}

int process(int cnt)
{
	int x = 4;
	int needCode = 1;
	fi(cnt)
	{
		fj(sz(s))
		{
			int c = getCode(s[j]);
			x = mul(x, c);
			if (x == needCode && needCode < 3)
			{
				x = 4;
				needCode++;
			}
		}
	}
	if (needCode < 3)
		return 0;
	return x;
}

int calcToEnd(int val)
{
	fj(sz(s))
	{
		int c = getCode(s[j]);
		val = mul(val, c);
	}
	return val;
}

void solve(int test_num)
{
	cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	auto minx = (int)min(30LL, x);
	auto res = process(minx);
	x -= minx;
	if (res && x)
	{
		if (x < 30)
		{
			fi(x)
				res = calcToEnd(res);
		}
		else
		{
			_(used, -1);
			int len = -1, pre = 0, val = res;
			fi(30)
			{
				val = calcToEnd(val);
				int q = val + 4;
				if (used[q] >= 0)
				{
					len = i - used[q];
					pre = used[q];
					break;
				}
				used[q] = i;
			}
			assert(len > 0);
			fi(pre)
				res = calcToEnd(res);
			x -= pre;
			x %= len;
			fi(x)
				res = calcToEnd(res);
		}
	}
	printf("%s\n", res == 3 ? "YES" : "NO");
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
	{
		read();
		solve(i + 1);
	}
	return 0;
}