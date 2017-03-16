#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
typedef __int64 LL;

LL a[20];
LL dp[20][10];
LL E, R;
int n;

LL DP(int at, int energy)
{
	LL &ret = dp[at][energy];
	if(ret!=-1)
		return ret;

	if(at == n)
		return ret = 0;

	ret = 0;
	int i;
	LL now;
	for(i = 0; i <= energy; i++)
	{
		now = i*a[at] + DP(at+1, MIN(energy-i+R, E));
		ret = MAX(ret, now);
	}

	return ret;
}

int main()
{
//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt-0.out", "w", stdout);

	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);

//	freopen("B-large.in", "r", stdin);
//	freopen("B-large.out", "w", stdout);

	int ks, T;
	int i;

	scanf("%d", &T);
	for(ks = 1; ks <= T; ks++)
	{
		scanf("%I64d %I64d %d", &E, &R, &n);

		for(i = 0; i < n; i++)
		{
			scanf("%I64d", &a[i]);
		}

		MEM(dp, -1);
		LL ans = DP(0, E);

		printf("Case #%d: %I64d\n", ks, ans);
	}

	return 0;
}
