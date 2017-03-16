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

#define MAX 128

int S[1 << 10];

int SolveTest(int test)
{
	int n;
	scanf("%d", &n);

	int i, j, k;
	FOR(i, 0, n)
		scanf("%d", &S[i]);

	int s = 0;
	FOR(i, 0, n)
		s += S[i];

	printf("Case #%d:", test + 1);
	FOR(i, 0, n)
	{
		double Min = 0, Max = 1;
		FOR(j, 0, MAX)
		{
			double Mid = (Min + Max)/2;
			double value = S[i] + Mid*s;
			double res = 0;
			FOR(k, 0, n)
				res += max(0.0, (value - S[k])/s);

			if(res > 1)
				Max = Mid;
			else
				Min = Mid;
		}

		printf(" %.7lf", 100*Max);
	}

	printf("\n");
	return 0;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

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
