/* by Ashar Fuadi [fushar] */

#include <cstdio>
#include <cstring>

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

typedef long long ll;

#define pb push_back
#define mp make_pair

int T, N, X;
int s[300];

bool ok(double p, int x)
{
	double Y = p;
	double this_score = s[x] + X*p;
	
	REP(i, N) if (i != x)
	{
		double y = (this_score - s[i]) / X;
		if (y < 0) y = 0;
		Y += y;
	}
	return Y <= 1;
}

int main()
{
	scanf("%d\n", &T);
	REP(tc, T)
	{
		scanf("%d", &N);
		REP(i, N)
			scanf("%d", &s[i]);
		X = 0;
		REP(i, N)
			X += s[i];
		
		printf("Case #%d:", tc+1);
		REP(i, N)
		{
			double lo = 0, hi = 1;
			REP(fuu, 200)
			{
				double mid = (lo+hi)/2;
				if (ok(mid, i))
					lo = mid;
				else
					hi = mid;
			}
			printf(" %.10lf", hi*100);
		}
		printf("\n");
	}
}
