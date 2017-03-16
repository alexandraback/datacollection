#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
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
using namespace std;
typedef long long LL;
typedef unsigned int UI;

#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(b-1); k >= (a); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<bool> VB;

int main()
{
#ifdef HOME	
	clock_t startclock=clock();
	freopen ("A-small-attempt0.in","r",stdin);
	freopen ("A-small-attempt0.out","w",stdout);
	freopen ("out_err.txt","w",stderr);	
#endif
	int T;
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		LL r,t;
		scanf("%lld %lld",&r,&t);
		++r;
		LL lo=0,hi=2e9;
		if(r>1)
			hi=min<LL>(hi,t/(2*r-1))+10;
		LL res=0;
		while(lo<=hi)
		{
			LL mi=lo+hi;
			mi/=2;
			LL ctr=mi*(2*r-1)+(mi*(mi-1))*2;
			if(ctr<=t)
			{
				res=mi;
				lo=mi+1;
			}
			else
			{
				hi=mi-1;
			}
		}
		printf("Case #%d: %lld\n",testcase,res);
	}
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-startclock));
	fflush(stderr);
#endif 
	return 0;
} 