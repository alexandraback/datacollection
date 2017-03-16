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

vector<vector<int> > g;
int ty[210];
int a[210];
int k,n;
int le[210];
vector<int> ans;
int was[210];
int wasd[210];
int wasc[210];
bool dfs(int v, int k)
{
	if (wasc[v])
		return false;
	if (wasd[v])
		return false;
	if (was[v])
		return false;
	wasd[v]=1;
	FOR(i,0,g[v].size())
		if (g[v][i]==k)
			return true;
	FOR(i,0,g[v].size())
		FOR(j,0,n)
			if (g[v][i]==ty[j])
			{
				bool f=dfs(j,k);
				if (f)
					return true;
			}
	return false;
}

int ca[210];
bool can(int to)
{
	bool f=true;
	MEMS(wasc,0);
	FOR(i,0,210)
		ca[i]=a[i];
	MEMS(le,0);
	FOR(i,0,n)
		if (was[i]==0)
			le[ty[i]]++;
	FOR(itt,0,to)
	{
		f=false;
		FOR(i,0,n)
		{
			if ((wasc[i]) || (was[i]))
				continue;
			MEMS(wasd,0);
			if ((ca[ty[i]]>0) && ((ca[ty[i]]>=le[ty[i]]) || dfs(i,ty[i])))
			{
				//ans.push_back(i);
				le[ty[i]]--;
				ca[ty[i]]--;
				FOR(j,0,g[i].size())
					ca[g[i][j]]++;
				wasc[i]=1;
				f=true;
				break;
			}
		}
		if (!f)
			break;
	}
	return f;
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
		ans.clear();
		scanf("%d%d",&k,&n);
		MEMS(a,0);
		FOR(i,0,k)
		{
			int v;
			scanf("%d",&v);
			a[v]++;
		}
		g.resize(n);
		MEMS(le,0);
		FOR(i,0,n)
		{
			int k;
			scanf("%d%d",&ty[i],&k);
			le[ty[i]]++;
			g[i].resize(k);
			FOR(j,0,k)
				scanf("%d",&g[i][j]);
		}
		bool f=true;
		MEMS(was,0);
		FOR(itt,0,n)
		{
			f=false;
			FOR(i,0,n)
			{
				if (was[i])
					continue;
				if (a[ty[i]]>0)
				{
					a[ty[i]]--;
					was[i]=1;
					FOR(j,0,g[i].size())
						a[g[i][j]]++;
					if (can(n-itt-1))
					{
						was[i]=1;
						ans.push_back(i);
						f=true;
						break;
					}
					else
					{
						a[ty[i]]++;
						was[i]=0;
						FOR(j,0,g[i].size())
							a[g[i][j]]--;
					}
				}
			}
			if (!f)
				break;
		}
		if (f)
		{
			FOR(i,0,ans.size())
			{
				if (i)
					printf(" ");
				printf("%d",ans[i]+1);
			}
			printf("\n");
		}
		else
			printf("IMPOSSIBLE\n");
		fprintf(stderr,"Case #%d solved\n",it+1);
	}
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}