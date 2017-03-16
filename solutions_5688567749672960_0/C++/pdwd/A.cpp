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

const LL inf = 1000000000000000LL;

#define MR 16
#define MS 10000010

char tab[MR];
int dp[MS];


LL reverse(LL x)
{
	//if(x % 10 == 0) return inf;

	int l = 0;
	while(x)
	{
		tab[l++] = x % 10;
		x /= 10;
	}
	LL pot = 1, res = 0;
	FORD(i,l,0)
	{
		res += tab[i]*pot;
		pot *= 10;
	}

	return res;
}

LL go(LL x)
{
	if(x == 1) return x;

	LL rev = reverse(x);

	return 1 + go(min(x-1,rev));
}

LL go1(LL x)
{
	int s = 1;
	dp[1] = 1;
	queue < int > Q;
	Q.push(s);
	while(!Q.empty())
	{
		s = Q.front(); Q.pop();
		if((LL)s == x) return (LL)dp[s];
		int s1 = s+1;
		int s2 = reverse(s);
		if(!dp[s1] || dp[s1] > dp[s] + 1)
		{
			dp[s1] = dp[s]+1;
			Q.push(s1);
		}
		if(!dp[s2] || dp[s2] > dp[s] + 1)
		{
			dp[s2] = dp[s]+1;
			Q.push(s2);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		LL n;
		scanf("%lld", &n);
		memset(dp,0,sizeof(dp));
		printf("Case #%d: %lld\n", c+1, go1(n));
	}
	return 0;
}