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
		cin >> E >> R >> N;

		int64 sum = 0;
		int64 maxV = 0;
		REP(i, N)
		{
			int64 v;
			cin >> v;
			sum += v;
			maxV = max(maxV, v);
		}
		R = min(R, E);
		int64 answer = (sum - maxV) * R + maxV * E;

		cout << "Case #" << test << ": " << answer << endl;
	}

	return 0;
}
