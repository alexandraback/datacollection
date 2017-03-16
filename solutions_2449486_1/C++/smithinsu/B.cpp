#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >


void precompute(void)
{
}

int t,kase,n,m,i,j,maxic[1024],maxir[1024],height[1024][1024],pos;
int main()
{
	precompute();
	while(scanf("%d",&t)!=EOF)
	{
		kase=1;
		while(t--)
		{
			scanf("%d%d",&n,&m);
			for(i=0;i<max(n,m);i++)
				maxir[i]=maxic[i]=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					scanf("%d",&height[i][j]);
					maxir[i]=max(maxir[i],height[i][j]);
					maxic[j]=max(maxic[j],height[i][j]);
				}
			}
			pos=1;
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)
					if(height[i][j]!=min(maxir[i],maxic[j]))
						pos=0;
			if(pos)
				printf("Case #%d: YES\n",kase);
			else
				printf("Case #%d: NO\n",kase);
			kase++;
		}
	}
	return 0;
}
