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

int f(int n)
{
	if (n == 0) return -1;

	auto mask = 0;
	for (auto i = 1; ; ++i)
	{
		auto a = i*n;
		while(a != 0)
		{
			auto d = a % 10;
			a /= 10;
			mask |= 1 << d;
		}

		if (mask == (1 << 10) - 1) return i*n;
	}
}

int SolveTest(int test)
{
	int n;
	scanf("%d", &n);
	auto res = f(n);
	if (res == -1)
		printf("Case #%d: INSOMNIA\n", test + 1);
	else
		printf("Case #%d: %d\n", test + 1, res);
	return 0;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	fgets(buf, 1024, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
