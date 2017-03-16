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
LL r, t;

int check(LL n)
{
		LL now = -3*n + 2*r*n + 2*n*(n+1);
	return ( now <= t );		
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
//	freopen("A-large.in", "r", stdin);
//	freopen("A-large.out", "w", stdout);

	int ks, T;
	LL lo, hi, mid;

	scanf("%d", &T);
	for(ks = 1; ks <= T; ks++)
	{
		scanf("%I64d%I64d", &r, &t);

		lo = 1;
		hi = MIN(2000000000, t/(2*r) + 10);
		while(lo < hi)
		{
			mid = (lo + hi + 1)/2;
			if(check(mid)) lo = mid;
			else hi = mid - 1;
		}

		printf("Case #%d: %I64d\n", ks, lo);
	}

	return 0;
}
