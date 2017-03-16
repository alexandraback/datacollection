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

int main()
{
	int testCount;
	cin >> testCount;
	FOR(test, 1, testCount)
	{
		int64 r, t, answer = 0;
		cin >> r >> t;
		while (1)
		{
			t -= 2 * r + 1;
			if (t < 0) break;
			answer++;
			r += 2;
		}
		cout << "Case #" << test << ": " << answer << endl;
	}

	return 0;
}
