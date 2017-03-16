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

int ni() { int a; scanf("%d", &a); return a; }
double nf() { double a; scanf("%lf", &a); return a; }
char sbuf[100005]; string ns() { scanf("%s", sbuf); return sbuf; }
long long nll() { long long a; scanf("%lld", &a); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	freopen("b-large.in", "r", stdin);
	freopen("b-large.out", "w", stdout);
}

int a, b, c;

void read()
{
	a = ni();
	b = ni();
	c = ni();
}

int bit(int x, int id)
{
	return (x >> id) & 1;
}

map < pair<pair<int, int>, int>, int > used;

lint get(int i, int a, int b, int c)
{
	if (i < 0)
		return 0;
	pair<pair<int, int>, int> p = mp(mp(a, b), i);
	if (used.find(p) != used.end())
		return used[p];
	lint sub = 0;
	if (!bit(c, i))
	{
		lint xa = max(0, a - (1 << i) + 1);
		lint xb = max(0, b - (1 << i) + 1);
		sub += xa * xb;
		bool ada = false, adb = false;
		int na = a, nb = b;
		if (a >= (1 << i))
		{
			na = (1 << i) - 1;
			a -= (1 << i);
			ada = true;
		}
		if (b >= (1 << i))
		{
			nb = (1 << i) - 1;
			b -= (1 << i);
			adb = true;
		}
		lint g1 = ada ? get(i - 1, a, nb, c) : 0;
		lint g2 = adb ? get(i - 1, na, b, c) : 0;
		lint g3 = get(i - 1, na, nb, c);
		sub += g1;
		sub += g2;
		sub += g3;
	}
	else
	{
		bool ada = false, adb = false;
		if (a >= (1 << i))
		{
			a -= (1 << i);
			ada = true;
		}
		if (b >= (1 << i))
		{
			b -= (1 << i);
			adb = true;
		}
		if (!ada || !adb)
			return used[p] = 0;
		sub += get(i - 1, a, b, c);
	}
	return used[p] = sub;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	lint sub = 0, res = (lint)a * (lint)b;
	a--;
	b--;
	c--;
	used.clear();
	sub = get(30, a, b, c);
	res -= sub;
	cout << res << endl;
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