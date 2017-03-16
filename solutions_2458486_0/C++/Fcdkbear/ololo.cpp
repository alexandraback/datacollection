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
int cnt1=0,cnt2=0;

int dp[(1<<20)+10];
int way[(1<<20)+10];
vector<vector<int> > g;
int ty[210];
int a[210];
int k,n;
int r(int mask)
{
	if ((mask+1==(1<<n)))
		return 1;
	if (dp[mask]!=-1)
		return dp[mask];
	FOR(i,0,n)
	{
		if ((mask>>i)&1)
			continue;
		if (a[ty[i]]>0)
		{
			a[ty[i]]--;
			FOR(j,0,g[i].size())
				a[g[i][j]]++;
			int v=r(mask|(1<<i));
			a[ty[i]]++;
			FOR(j,0,g[i].size())
				a[g[i][j]]--;
			if (v)
			{
				way[mask]=i;
				return dp[mask]=1;
			}
		}
	}
	return dp[mask]=0;
}

int main()
{
#ifdef Fcdkbear
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    double beg=clock();
#else
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d",&t);
	FOR(it,0,t)
	{
		printf("Case #%d: ",it+1);
		g.clear();

		scanf("%d%d",&k,&n);
		MEMS(a,0);
		FOR(i,0,k)
		{
			int v;
			scanf("%d",&v);
			a[v]++;
		}
		g.resize(n);
		FOR(i,0,n)
		{
			int k;
			scanf("%d%d",&ty[i],&k);
			g[i].resize(k);
			FOR(j,0,k)
				scanf("%d",&g[i][j]);
		}
		MEMS(dp,-1);
		int res=r(0);
		if (res)
		{
			int mask=0;
			while (mask+1!=(1<<n))
			{
				if (mask)
					printf(" ");
				printf("%d",way[mask]+1);
				mask|=(1<<way[mask]);
			}
			printf("\n");
		}
		else
			printf("IMPOSSIBLE\n");
	}
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}