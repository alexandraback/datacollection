#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <list>
using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(b-1); k >= (a); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))
#define EPS 1e-9

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

int tmp[8];

int reverse(int a)
{
	int ctr=0;
	while(a)
	{
		tmp[ctr++]=a%10;
		a/=10;
	}
	int b=0;
	REP(i,ctr)
	{
		b*=10;
		b+=tmp[i];
	}
	return b;
}

int main( int argc, char* argv[] ) {
#ifdef HOME
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out", "wb", stdout);
#endif
	vector<int> dp(1e6+1,(int)1e9);
	dp[1]=1;
	FOR(i,1,1e6)
	{
		dp[i+1]=min(dp[i]+1,dp[i+1]);
		int rev=reverse(i);
		dp[rev]=min(dp[i]+1,dp[rev]);
	}
	int T,N;
	cin>>T;
	FOR(tc,1,T+1)
	{
		cin>>N;
		cout << "Case #" << tc << ": "  << dp[N] << endl;
	}
	return 0;
}

