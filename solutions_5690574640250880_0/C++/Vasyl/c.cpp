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

char A[64][64];
int R[64][64][64 * 64];

int f(int r, int c, int m)
{
	int i, j, k, l;
	FOR(i, 0, r)
		FOR(j, 0, c)
		A[i][j] = '*';

	m = r*c - m;
	if (r == 1 || c == 1 || m == 1)
	{
		FOR(i, 0, r)
			FOR(j, 0, c)
			if (m != 0)
			{
				A[i][j] = '.';
				--m;
			}

		A[0][0] = 'c';
		return 1;
	}

	CLEAR(R, -1);
	FOR(i, 2, c + 1)
		R[2][i][2 * i] = 0;

	FOR(i, 0, r)
		FOR(j, 0, c + 1)
		FOR(k, 0, m + 1)
		if (R[i][j][k] != -1)
			FOR(l, 2, j + 1)
				R[i + 1][l][k + l] = j;

	FOR(i, 0, r + 1)
		FOR(j, 0, c + 1)
		if (R[i][j][m] != -1)
		{
			while (i != 2)
			{
				FOR(k, 0, j)
					A[i - 1][k] = '.';

				l = m;
				m -= j;
				j = R[i][j][l];
				--i;
			}

			FOR(k, 0, j)
				A[0][k] = A[1][k] = '.';

			A[0][0] = 'c';
			return 1;
		}

	return 0;
}

int SolveTest(int test)
{
	int r, c, m;
	scanf("%d%d%d", &r, &c, &m);

	int res = f(r, c, m);

	printf("Case #%d:\n", test + 1);

	if (res == 0)
		printf("Impossible\n");
	else
	{
		int i;
		FOR(i, 0, r)
		{
			A[i][c] = 0;
			printf("%s\n", A[i]);
		}
	}

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
