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
	freopen ("C-small-1-attempt0.in","r",stdin);
	freopen ("C-small-1-attempt0.out","w",stdout);
	freopen ("out_err.txt","w",stderr);	
#endif
	int T;
	scanf("%d",&T);
	printf("Case #1:\n");
	FOR(testcase,1,T+1)
	{
		int R,N,M,K;
		scanf("%d %d %d %d",&R,&N,&M,&K);
		REP(round,R)
		{
			VI v(K);
			VI w(M+1);
			REP(i,K)
			{
				scanf("%d",&v[i]);
				int tmp=v[i];
				int ss=0;
				FOR(j,2,M+1)
				{
					if (M>3 && (j==2 || j==4)) continue;
					int ctr=0;
					while(tmp%j==0)
						++ctr,tmp/=j;
					w[j]=max(w[j],ctr);
					ss+=ctr;
				}
				if(M>3)
				{
					if(tmp%4==2)
					{
						w[2]=max(1,w[2]);
						++ss;
						tmp/=2;
					}
					int rem=N-ss;
					REP(i,rem) if(tmp%2==0)
						tmp/=2;
					int ctr2=0;
					while(tmp%2==0)
						tmp/=2,++ctr2;
					w[4]=max(ctr2,w[4]);
					ss+=ctr2;
				}
			}
			int su=0;
			REP(i,M+1)
			{
				su+=w[i];
			}
			int rem=N-su;
			REP(i,rem)
				++w[2+rand()%(M-1)];
			string res;
			REP(i,M+1)
			{
				REP(j,w[i])
					res+='0'+i;
			}
			//printf("Case #%d: %s\n",testcase,res.c_str());
			printf("%s\n",res.c_str());
		}
	}
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-startclock));
	fflush(stderr);
#endif 
	return 0;
} 