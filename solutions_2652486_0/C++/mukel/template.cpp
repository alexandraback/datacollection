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
#include <cassert>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(c) ((int)(c).size())
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)

typedef long long int64;

int R, N, M, K;

int prod[6][6][6][126];

int main()
{
	FOR(a, 2, 5)
	FOR(b, 2, 5)
	FOR(c, 2, 5)
	{
		REP(i, 8)
		{
			int p = 1;
			if (i & 1) p *= a;
			if (i & 2) p *= b;
			if (i & 4) p *= c;
			prod[a][b][c][ p ]++;
		}
	}

	int testCount;
	cin >> testCount;

	FOR(test, 1, testCount)
	{
		cout << "Case #" << test << ":" << endl;

		cin >> R >> N >> M >> K;

		REP(r, R)
		{
			int s[K];
			REP(k, K) cin >> s[k];

			int64 maxMul = -1;
			vector< int > answer = {1, 1, 1};

			FOR(a, 2, M)
			FOR(b, 2, M)
			FOR(c, 2, M)
			{
				int64 mul = 0;
				REP(k, K)
				{
					int p = prod[a][b][c][ s[k] ];
					if (p == 0)
					{
						mul = -1;
						break;
					}
					mul *= p;
				}
				if (mul > maxMul)
				{
					maxMul = mul;
					answer[0] = a;
					answer[1] = b;
					answer[2] = c;
				}
			}

			cout << answer[0] << answer[1] << answer[2] << endl;
		}
	}

	return 0;
}
