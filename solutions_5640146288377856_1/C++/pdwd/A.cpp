#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

#define MR 50

int jest[MR];
int dp[MR];

int czyJest(int dl, int W)
{
	if(jest[dl] > -1) return jest[dl];
	if(dl < 2*W) return jest[dl] = 1;
	
	int res = MR;
	FOR(i,1,dl) res = min(res, czyJest(i, W) + czyJest(dl-i, W));

	return jest[dl] = res;
}

int go(int dl, int W)
{
	if(dp[dl] != -1) return dp[dl];
	if(dl == W) return dp[dl] = W;
	if(dl <= 2*W) return dp[dl] = W+1;
	
	int res = 1 + go(dl-W, W);
	FORQ(i,W+1,dl-W) res = min(res,
		max(czyJest(i-1, W) + go(dl-i, W), go(i-1, W) + czyJest(dl-i, W)) + 1);

	return dp[dl] = max(res, W+1);
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		REP(i,MR) jest[i] = dp[i] = -1;
		int R, C, W;
		scanf("%d%d%d", &R, &C, &W);	
		int res = (R-1)*czyJest(C,W) + go(C,W);
		printf("Case #%d: %d\n", c+1, res);
	}
	return 0;
}