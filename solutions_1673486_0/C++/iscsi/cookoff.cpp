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

using namespace std;
typedef unsigned long long LL;
#define FOR(k,a,b) for(LL k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(b-1); k >= (a); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))


int main()
{
#ifdef HOME
	clock_t start=clock();
	freopen ("A-small-attempt1.in","r",stdin);
	freopen ("A-small-attempt1.out","w",stdout);
#endif
	int T,A,B;
	double p,p2;
	double res;
	double d;
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		scanf("%d %d",&A,&B);
		res=B+2;
		REP(i,A)
		{
			scanf("%lf",&p);
			if(i==0)
				p2=p;
			else
				p2*=p;
			d=A-i-1+B-i-1+1+(1-p2)*(B+1);
			if(d<res)
				res=d;
		}
		cout << "Case #" << testcase << ": ";
		printf("%.10lf\n",res);
	}
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
#endif
	return 0;
} 