#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

double eps=1e-9;
int n,e,r;
int dp[15][15];
int a[15];
int rec(int ne, int np)
{
	if (np==n)
		return 0;
	if (dp[ne][np]!=-1)
		return dp[ne][np];
	int res=0;
	FOR(i,0,ne+1)
	{
		int cur=a[np]*i+rec(min(ne-i+r,e),np+1);
		res=max(res,cur);
	}
	return dp[ne][np]=res;
}
int main()
{
#ifdef Fcdkbear
    double beg=clock();
#endif
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	
	int t;
	scanf("%d",&t);
	FOR(it,1,t+1)
	{
		e,r,n;
		scanf("%d%d%d",&e,&r,&n);
		FOR(i,0,n)
			scanf("%d",&a[i]);
		MEMS(dp,-1);
		int res=rec(e,0);
		printf("Case #%d: %d\n",it,res);
	}
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}