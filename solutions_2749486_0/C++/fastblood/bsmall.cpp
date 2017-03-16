#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define _(a, b) memset(a, b, sizeof(a))

typedef long long lint;
typedef unsigned long long ull;

const int INF = 1000000000;
const lint LINF = 4000000000000000000ll;
const double eps = 1e-9;

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int TEST = 0;

bool solve()
{
	string res = "";

	int x, y;
	scanf("%d%d", &x, &y);

	char s = x < 0 ? 'E' : 'W';
	char e = x < 0 ? 'W' : 'E';
	x = abs(x);
	for (int i = 0; i < x; i++)
	{
		res.pb(s);
		res.pb(e);
	}

	s = y < 0 ? 'N' : 'S';
	e = y < 0 ? 'S' : 'N';
	y = abs(y);
	for (int i = 0; i < y; i++)
	{
		res.pb(s);
		res.pb(e);
	}

	TEST++;
	printf("Case #%d: %s\n", TEST, res.c_str());

	return false;
}

int main()
{
	prepare();
	int tn;
	for (scanf("%d", &tn); tn; tn--)
		solve();
	return 0;
}