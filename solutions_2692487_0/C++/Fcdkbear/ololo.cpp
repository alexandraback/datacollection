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
#include <unordered_map>
 
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


int dp[101][1000010];
char was[101][1000010];
int a[110];
int now;
int n;
int r(int p, int sz)
{
	if (p==n)
		return 0;
	if (was[p][sz]==now)
		return dp[p][sz];
	was[p][sz]=now;
	if (sz>a[p])
		return dp[p][sz]=r(p+1,min(1000001,sz+a[p]));
	int res=10000000000;
	if (sz!=1)
		res=min(res,1+r(p,min(1000001,sz+sz-1)));
	res=min(res,1+r(p+1,sz));
	return dp[p][sz]=res;
}

int main()
{
#ifdef Fcdkbear
    double beg=clock();
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#else
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

	int t;
	cin>>t;
	for (now=1; now<=t; ++now)
	{
		int v;
		scanf("%d%d",&v,&n);
		FOR(i,0,n)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int res=r(0,v);
		printf("Case #%d: %d\n",now,res);
	}

#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}