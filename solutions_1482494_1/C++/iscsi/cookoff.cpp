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
	freopen ("B-large.in","r",stdin);
	freopen ("B-large.out","w",stdout);
#endif
	int T,N;
	int a[1002],b[1002];
	bool aa[1002],bb[1002];
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		scanf("%d",&N);
		int star=0,round=0,remain=2*N;
		REP(i,N)
		{
			scanf("%d %d",&(a[i]),&(b[i]));
			aa[i]=false;
			bb[i]=false;
		}
		while(remain)
		{
			int best1=-1,best2=-1,best1v=-1;
			REP(i,N)
			{
				if(!aa[i] && star>=a[i] && b[i]>best1v)
				{
					best1=i;
					best1v=b[i];
				}
				if(!bb[i] && star>=b[i])
				{
					best2=i;
					break;
				}
			}
			if(best2>-1)
			{
				if(!aa[best2])
				{
					aa[best2]=true;
					++star;
					--remain;
				}
				++round;
				++star;
				bb[best2]=true;
				--remain;
			}
			else if(best1>-1)
			{
				aa[best1]=true;
				--remain;
				++star;
				++round;
			}
			else
			{
				round=-1;
				break;
			}
		}
		if(round==-1)
			cout << "Case #" << testcase << ": Too Bad"<< endl;
		else
			cout << "Case #" << testcase << ": " << round<< endl;

	}
#ifdef HOME
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
#endif
	return 0;
} 