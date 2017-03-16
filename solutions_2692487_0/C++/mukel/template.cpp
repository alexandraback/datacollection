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

int main()
{
	int testCount;
	cin >> testCount;
	FOR(test, 1, testCount)
	{
		int A, N;
		cin >> A >> N;
		deque< int > nums;

		REP(i, N)
		{
			int x;
			cin >> x;
			nums.push_back(x);
		}

		sort(ALL(nums));

		int ans = (int)1e6, curSteps = 0;

		while (!nums.empty())
		{
			while (!nums.empty() && nums.front() < A)
			{
				A += nums.front();
				nums.pop_front();
			}
			ans = min(ans, curSteps + SZ(nums));
			curSteps++;
			A += A - 1;
			if (A == 1) break;
		}

		printf( "Case #%d: %d\n", test, ans );
	}

	return 0;
}
