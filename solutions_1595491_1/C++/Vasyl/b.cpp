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

int A[128];
int R[128][128];

int SolveTest(int test)
{
	int n, s, p;
	scanf("%d%d%d", &n, &s, &p);

	int i, j, k;
	FOR(i, 0, n)
		scanf("%d", &A[i]);

	CLEAR(R, 0);
	FOR(i, 0, n + 1)
		FOR(j, 0, i + 1)
		{
			R[i + 1][j] = max(R[i + 1][j], R[i][j]);
			R[i][j + 1] = max(R[i][j + 1], R[i][j]);

			if(3*p - 2 <= A[i])
				R[i + 1][j] = max(R[i + 1][j], R[i][j] + 1);
			if(p > 1 && 3*p - 4 <= A[i])
				R[i + 1][j + 1] = max(R[i + 1][j + 1], R[i][j] + 1);
		}

	printf("Case #%d: %d\n", test + 1, R[n][s]);
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
