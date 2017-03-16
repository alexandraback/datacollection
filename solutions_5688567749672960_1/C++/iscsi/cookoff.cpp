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

int tmp[20];
int ctr;

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


LL calc(const vector<int>& w)
{
	int tmp2[20];
	REP(i,ctr)
	{
		tmp2[i]=0;
	}
	tmp2[ctr-1]=1;
	LL res = w[ctr];
	LL tt = 1;
	bool rev = 0;
	REP(i,ctr/2)
	{
		res+=(tmp[i]-tmp2[i])*tt;
		tt*=10;
	}
	if(ctr%2)
	{
		res+=tmp[ctr/2]*tt;
	}
	FOR(i,(ctr+1)/2,ctr)
	{
		tt/=10;
		if(!rev && tmp[i]>tmp2[i])
		{
			res+=1;
			rev=1;
		}
		res+=(tmp[i]-tmp2[i])*tt;
	}
	return res;
}


LL fullcalc(LL a, const vector<int>& w)
{
	tmp[20];
	ctr = 0;
	while(a)
	{
		tmp[ctr++]=a%10;
		a/=10;
	}
	LL res1 = calc(w);
	return res1;
}


int main( int argc, char* argv[] ) {
#ifdef HOME
	freopen("A-large.in","r",stdin);
	freopen("A-large.out", "wb", stdout);
#endif
	vector<int> dp(1e6+1,(int)1e9);
	dp[1]=1;
	FOR(i,1,1e6)
	{
		dp[i+1]=min(dp[i]+1,dp[i+1]);
		int rev=reverse(i);
		dp[rev]=min(dp[i]+1,dp[rev]);
	}
	vector<int> w(20);
	w[1]=1;
	w[2]=10;
	LL curr=10;
	FOR(i,3,20)
	{
		curr*=10;
		w[i]=fullcalc(curr-1,w)+1;
	}
	/*FOR(i,20,1e6)
	{
		if(dp[i]!=fullcalc(i,w))
		{
			int alma = 42;
		}
	}*/

	int T;
	LL N;
	cin>>T;
	FOR(tc,1,T+1)
	{
		cin>>N;
		
		LL rs = fullcalc(N,w);
		if(N%10==0)
		{
			rs = fullcalc(N-1,w);
			++rs;
		}
		if(N<10)
			rs = N;
		cout << "Case #" << tc << ": "  << rs << endl;
	}
	return 0;
}

