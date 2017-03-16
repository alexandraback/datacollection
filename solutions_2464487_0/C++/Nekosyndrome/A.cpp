#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 
using namespace std;
typedef long long LL;
int test;
double r,t;
LL ll,rr,mid;
double use(LL x)
{
	double re = 2*r*x;
	re += (double)( 2+ (double)(x-1)*4 ) * (double)x / 2.0;
	return re;
}
int main()
{
	scanf("%d",&test);
	REP(tt,1,test)
	{
		scanf("%lf %lf",&r,&t);

	//	REP(i,1,5)printf("%f\n",use(i));
		ll=1,rr=(LL)1e18;
		while(ll<rr-1)
		{
			mid=(ll+rr)/2;
			if(use(mid) <= t)ll=mid;
			else rr=mid-1;
		}
		if(ll==rr-1 && use(rr)<=t)ll++;
		printf("Case #%d: %I64d\n",tt,ll);
	}
	return 0;
}

