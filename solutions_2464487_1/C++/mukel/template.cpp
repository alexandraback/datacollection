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

typedef unsigned long long int64;

int64 R, T, answer;

bool ok(int64 n)
{
	return n * (2*R + 1) + 4 * (n * (n - 1) / 2) <= T;
}

int main()
{
	int testCount;
	cin >> testCount;
	FOR(test, 1, testCount)
	{
		cin >> R >> T;

		int64 lo = 1, hi = min((int64)sqrt(T), T / (2*R + 1)) + 100;

		while (lo <= hi)
		{
			int64 mid = (lo + hi) / 2;
			if (ok(mid))
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		answer = lo - 1;

		cout << "Case #" << test << ": " << answer << endl;
	}

	return 0;
}
