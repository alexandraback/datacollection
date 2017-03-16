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

int SolveTest(int test)
{
	int a, b;
	scanf("%d%d", &a, &b);

	int res = 0;
	int power = 1;
	while(power <= a)
		power *= 10;

	vector<PII> v;
	for(int p = 10; p < power; p *= 10)
	{
		int q = power/p;
		int i, j;
		FOR(i, p/10, p)
			FOR(j, q/10, q)
			{
				int x = i*q + j;
				int y = j*p + i;
				if(a <= x && x < y && y <= b)
					v.PB(PII(x, y));
			}
	}

	sort(ALL(v));

	printf("Case #%d: %d\n", test + 1, int(unique(ALL(v)) - v.begin()));
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

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
