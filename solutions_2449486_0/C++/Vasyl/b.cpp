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

int A[128][128];
int R[128][128];

int SolveTest(int test)
{
	int n, m;
	scanf("%d%d", &n, &m);

	int i, j;
	FOR(i, 0, n)
		FOR(j, 0, m)
		{
			scanf("%d", &A[i][j]);
			R[i][j] = 128;
		}

	FOR(i, 0, n)
	{
		int r = 0;
		FOR(j, 0, m)
			r = max(r, A[i][j]);

		FOR(j, 0, m)
			R[i][j] = min(R[i][j], r);
	}

	FOR(j, 0, m)
	{
		int r = 0;
		FOR(i, 0, n)
			r = max(r, A[i][j]);

		FOR(i, 0, n)
			R[i][j] = min(R[i][j], r);
	}

	int res = 1;
	FOR(i, 0, n)
		FOR(j, 0, m)
			if(A[i][j] != R[i][j])
				res = 0;

	printf("Case #%d: %s\n", test + 1, res == 0 ? "NO" : "YES");
	return 0;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

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
