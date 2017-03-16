// Alfonso2 Peterssen
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(c) ((int)(c).size())
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)

typedef long long int64;

const int
	MAXN = 200,
	MAXE = 6,
	oo = (1 << 30);

int E, R, N;
int64 dp[MAXN][MAXE];

int main()
{
	int testCount;
	cin >> testCount;

	FOR(test, 1, testCount)
	{


		REP(i, MAXN)
		REP(j, MAXE)
			dp[i][j] = 0;

		cin >> E >> R >> N;

		dp[0][E] = 0;

		FOR(i, 1, N)
		{
			int v;
			cin >> v;
			FOR(e1, 0, E)
			FOR(e2, 0, e1)
				dp[i][min(E, e1 - e2 + R)] = max(dp[i][min(E, e1 - e2 + R)], dp[i - 1][e1] + e2 * v);
		}

		int64 answer = *max_element(dp[N], dp[N] + E + 1);

		cout << "Case #" << test << ": " << answer << endl;
	}

	return 0;
}
