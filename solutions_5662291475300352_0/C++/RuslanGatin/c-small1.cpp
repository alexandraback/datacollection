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

int n;
double d[12], m[12];

void read()
{
	n = ni();
	int cc = 0;
	fi(n)
	{
		d[cc] = nf();
		int h = ni();
		m[cc] = nf();
		fj(h - 1)
		{
			m[cc + 1] = m[cc] + 1;
			d[cc + 1] = d[cc];
			cc++;
		}
		cc++;
	}
	n = cc;
}

bool eq(double a, double b)
{
	return a - b <= eps && b - a <= eps;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	if (n < 2 || eq(m[0], m[1]))
	{
		printf("0\n");
		return;
	}
	if (d[0] > d[1])
	{
		swap(d[0], d[1]);
		swap(m[0], m[1]);
	}
	if (m[0] < m[1])
	{
		double q = d[1] - d[0];
		double x = q * m[1] / (m[1] - m[0]) + d[0];
		if (x > 360 + eps)
		{
			printf("0\n");
			return;
		}
		d[0] = d[1] = x;
		swap(m[0], m[1]);
	}
	double q = 360 - (d[1] - d[0]);
	double x = q * m[1] / (m[0] - m[1]) + d[0];
	if (x > 360 + eps)
		printf("0\n");
	else
		printf("1\n");
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