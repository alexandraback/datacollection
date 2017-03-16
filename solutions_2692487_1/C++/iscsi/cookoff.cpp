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
typedef vector<pair<int,int> > VII;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<bool> VB;


int main()
{
#ifdef HOME	
	clock_t startclock=clock();
	freopen ("A-large.in","r",stdin);
	freopen ("A-large.out","w",stdout);
	freopen ("out_err.txt","w",stderr);	
#endif
	int T;
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		LL A;
		int N;
		scanf("%lld %d",&A,&N);
		VL v(N);
		REP(i,N)
			scanf("%lld",&v[i]);
		sort(v.begin(),v.end());
		int res=N;
		REP(round,N)
		{
			LL su=A;
			int i=0;
			int used=round;
			while(i<N)
			{
				if(su>v[i])
				{
					su+=v[i];
					++i;
				}
				else
				{
					if(used==0)
						break;
					else
					{
						--used;
						su+=su-1;
					}
				}
			}
			res=min(res,N-i+round);
		}
		printf("Case #%d: %d\n",testcase,res);
	}
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-startclock));
	fflush(stderr);
#endif 
	return 0;
} 