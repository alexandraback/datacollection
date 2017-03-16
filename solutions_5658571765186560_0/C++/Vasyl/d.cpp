//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int f(int x, int r, int c)
{
	if (r < c)
		swap(r, c);

	if (x >= 7)
		return 0;

	if ((r*c) % x != 0)
		return 0;

	int a, b;
	FOR(a, 1, x + 1)
	{
		b = x + 1 - a;
		if (a < b)
			continue;

		if (a > r || b > c)
			return 0;

		if (a == r && a != 1 && b > 2)
			return 0;
		if (b == c && b != 1 && a > 2)
			return 0;
	}

	return 1;
}

int SolveTest(int test)
{
	int x, r, c;
	scanf("%d%d%d", &x, &r, &c);

	printf("Case #%d: %s\n", test + 1, f(x, r, c) == 0 ? "RICHARD" : "GABRIEL");
	return 0;
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
