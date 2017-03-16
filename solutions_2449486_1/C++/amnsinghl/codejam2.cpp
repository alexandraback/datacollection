#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#define SET(p)	 		memset(p,-1,sizeof(p))
#define CLR(p) 			memset(p,0,sizeof(p))
#define LL 				long long int
#define ULL		 		unsigned long long int
#define S(n)			scanf("%d",&n)
#define Sl(n)			scanf("%lld",&n)
#define Sf(n)			scanf("%lf",&n)
#define Ss(n)			scanf("%s",n)
#define INF				(int)1e9
#define LINF			(long long)1e18
#define EPS				1e-9
#define FOR(i,a,b)		for(int i=a;i<b;i++)
#define REP(i,n)		FOR(i,0,n)
using namespace std;
int a[300][300];
int b[300][300];
int main()
{
	int t,i,j,k,n,m;
	#ifndef ONLINE_JUDGE
	freopen("example.txt","r",stdin);
	freopen("op.txt","w",stdout);
	#endif
	S(t);
	int zz=0;
	while(t--)
	{
		zz++;
		S(n);S(m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				S(a[i][j]);
		printf("Case #%d: ",zz);
		for(i=0;i<n;i++)
		{
			int maxn=0;
			for(j=0;j<m;j++)
			{
				if(a[i][j]>maxn)
					maxn=a[i][j];
			}
			for(j=0;j<m;j++)
				b[i][j]=maxn;
		}
		for(j=0;j<m;j++)
		{
			int maxn=0;
			for(i=0;i<n;i++)
			{
				if(a[i][j]>maxn)
					maxn=a[i][j];
			}
			for(i=0;i<n;i++)
			{
				if(b[i][j]>maxn)
					b[i][j]=maxn;
				if(b[i][j]!=a[i][j])
				{
					printf("NO\n");
					goto rr;
				}
			}
		}
		printf("YES\n");
		rr:;
	
	}
	return 0;
}
