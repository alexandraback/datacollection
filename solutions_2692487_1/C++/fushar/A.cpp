/* by Ashar Fuadi (fushar) */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0, _n = (int)n; i < _n; i++)
#define FOR(i,a,b) for (int i = (int)a, _b = (int)b; i <= _b; i++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

#define pb push_back
#define mp make_pair

int T, N;
ll A, mote[105];

int solve(int x)
{
	ll cur = A;
	int res = 0;
	REP(i, x)
	{
		if (cur == 1 && cur <= mote[i])
			return 999999999;
		while (cur <= mote[i])
		{
			res++;
			cur += cur-1;
		}
		cur += mote[i];
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	REP(tc, T)
	{
		scanf("%lld%d", &A, &N);
		REP(i, N)
			scanf("%lld", &mote[i]);
		sort(mote, mote+N);

		int res = N;
		REP(i, N+1)
			res = min(res, N-i + solve(i));
		printf("Case #%d: %d\n", tc+1, res);
	}
}