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
	freopen("a-small.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
}

void panic(bool expression = false)
{
	if (!expression)
	{
		cerr << "PANIC!" << endl;
		assert(false);
	}
}

char f[10][10];

bool checkHor(int index, char c)
{
	for (int i = 0; i < 4; i++)
	{
		if (f[index][i] != 'T' && f[index][i] != c)
			return false;
	}
	return true;
}

bool checkVer(int index, char c)
{
	for (int i = 0; i < 4; i++)
	{
		if (f[i][index] != 'T' && f[i][index] != c)
			return false;
	}
	return true;
}

bool check1(char c)
{
	for (int i = 0; i < 4; i++)
	{
		if (f[i][i] != 'T' && f[i][i] != c)
			return false;
	}
	return true;
}

bool check2(char c)
{
	for (int i = 0; i < 4; i++)
	{
		if (f[i][3 - i] != 'T' && f[i][3 - i] != c)
			return false;
	}
	return true;
}

bool checkT()
{
	fi(4)
	{
		fj(4)
		{
			if (f[i][j] == '.')
				return true;
		}
	}
	return false;
}

bool checkHorVer(char c)
{
	fi(4)
	{
		if (checkHor(i, c) || checkVer(i, c))
			return true;
	}
	return false;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	fi(4)
		scanf("%s", f[i]);
	if (check1('X') || check2('X') || checkHorVer('X'))
		printf("X won\n");
	else if (check1('O') || check2('O') || checkHorVer('O'))
		printf("O won\n");
	else if (checkT())
		printf("Game has not completed\n");
	else
		printf("Draw\n");
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