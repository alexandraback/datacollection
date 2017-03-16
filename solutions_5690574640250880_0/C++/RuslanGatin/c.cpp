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

const int maxn = 55;

char a[maxn][maxn], b[maxn][maxn];
int n, m, bombs;

void read()
{
	n = ni();
	m = ni();
	bombs = ni();
}

bool gogo(int rb)
{
	if (rb == 1)
		return false;
	_(a, 0);
	fi(n)
	{
		fj(m)
			a[i][j] = '.';
	}
	m -= rb;
	fi(n - 2)
	{
		int z = min(bombs, m);
		if (z == m - 1)
			z--;
		fj(z)
			a[i][j] = '*';
		bombs -= z;
	}
	fj(m)
	{
		if (bombs < 2)
			break;
		a[n - 1][j] = a[n - 2][j] = '*';
		bombs -= 2;
	}
	m += rb;
	a[n - 1][m - 1] = 'c';
	return bombs <= 0;
}

bool canFill(int x, int y, int dx, int dy)
{
	if (dx == 1 || dy == 1)
		return false;
	if (x == n && dy || y == m && dx)
		return false;
	_(a, 0);
	fi(n)
	{
		fj(m)
			a[i][j] = '.';
	}
	fi(n)
	{
		fj(m)
		{
			if (i < x && j < y)
				continue;
			if (i < x + 1 && j < dy)
				continue;
			if (i < dx && j < y + 1)
				continue;
			a[i][j] = '*';
		}
	}
	a[0][0] = 'c';
	return true;
}

bool go3(int x, int y)
{
	fi(x + 1)
	{
		int j = n * m - x * y - i - bombs;
		if (j < 0 || j > y)
			continue;
		if (canFill(x, y, i, j))
			return true;
	}
	return false;
}

bool go()
{
	int _b = bombs;
	fi(n + 1) if (i >= 2)
	{
		fj(m + 1) if (j >= 2)
		{
			bombs = _b;
			int sub1 = i * j;
			int sub2 = i * j + i + j;
			if (n * m - sub1 >= bombs && n * m - sub2 <= bombs)
			{
				if (go3(i, j))
				{
					bombs = 0;
					return true;
				}
			}
		}
	}
	return false;
	fj(m)
	{
		bombs = _b;
		if (gogo(j))
			return true;
	}
	return false;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	_(a, 0);
	_(b, 0);
	printf("Case #%d:\n", test_num);
	int _b = bombs;
	if (n == 1 || m == 1 || bombs + 1 == n * m)
	{
		fi(n)
		{
			fj(m)
			{
				a[i][j] = bombs > 0 ? '*' : '.';
				bombs--;
			}
		}
		a[n - 1][m - 1] = 'c';
	}
	else if (bombs + 4 <= n * m)
	{
		if (!go())
		{
			bombs = _b;
			swap(n, m);
			if (go())
			{
				swap(n, m);
				fi(n)
				{
					fj(m)
						b[i][j] = a[j][i];
				}
				memcpy(a, b, sizeof(a));
			}
			else
				swap(n, m);
		}
	}
	if (bombs > 0)
	{
		printf("Impossible\n");
		cerr << n << " " << m << " " << _b << endl;
		return;
	}
	fi(n)
		printf("%s\n", a[i]);
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