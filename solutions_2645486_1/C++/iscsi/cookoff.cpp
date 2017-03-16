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
	freopen ("B-large.in","r",stdin);
	freopen ("B-large.out","w",stdout);
	freopen ("out_err.txt","w",stderr);	
#endif
	int T;
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		int E,R,N;
		scanf("%d %d %d",&E,&R,&N);
		VI v(N);
		REP(i,N)
			scanf("%d",&(v[i]));
		LL res=0;
		VB b(N,1);
		VI e(N,E);
		REP(round,N) 
		{
			int idx=-1;
			int bestv=-1;
			REP(i,N) if(b[i] && v[i]>bestv)
			{
				idx=i;
				bestv=v[i];
			}
			b[idx]=0;
			res+=1LL*bestv*e[idx];
			int tmp=0;
			for(int i=idx-1;i>-1;--i)
			{
				tmp+=R;
				if(!b[i]) 
				{
					int vvv=max(tmp-E,0);
					FOR(j,i+1,idx)
						e[j]=min(vvv,e[i]);
					break;
				}
				if(tmp>E) break;
				e[i]=min(tmp,e[i]);
			}
			tmp=0;
			for(int i=idx+1;i<N;++i)
			{
				tmp+=R;
				if(!b[i]) 
				{
					int vvv=max(tmp-E,0);
					FOR(j,idx+1,i+1)
						e[j]=min(vvv,e[i]);
					break;
				}
				if(tmp>E) break;
				e[i]=min(tmp,e[i]);
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