//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
using namespace std;

pair<LL,int> line1[150],line2[150];
int t,n,m;

LL dfs(LL jum1, int jen1, int i, LL jum2, int jen2, int j)
{
	if ((i < n) && (j < m))
	{
		if (jen1 != 0)
		{
			if (jen1 == line2[j].se)
			{
				if (jum1 < line2[j].fi)
					return jum1+max(dfs(0,0,i+1,line2[j].fi-jum1,jen1,j),dfs(0,0,i+1,0,0,j+1));
				else if (jum1 > line2[j].fi)
					return line2[j].fi+max(dfs(jum1-line2[j].fi,jen1,i,0,0,j+1),dfs(0,0,i+1,0,0,j+1));
				else
					return jum1+dfs(0,0,i+1,0,0,j+1);
			}
			else
				return dfs(jum1,jen1,i,0,0,j+1);
		}
		else if (jen2 != 0)
		{
			if (jen2 == line1[i].se)
			{
				if (jum2 < line1[i].fi)
					return jum2+max(dfs(line1[i].fi-jum2,jen2,i,0,0,j+1),dfs(0,0,i+1,0,0,j+1));
				else if (jum2 > line1[i].fi)
					return line1[i].fi+max(dfs(0,0,i+1,jum2-line1[i].fi,jen2,j),dfs(0,0,i+1,0,0,j+1));
				else
					return jum2+dfs(0,0,i+1,0,0,j+1);
			}
			else
				return dfs(0,0,i+1,jum2,jen2,j);
		}
		else
		{
			if (line1[i].se == line2[j].se)
			{
				if (line1[i].fi < line2[j].fi)
					return line1[i].fi+max(dfs(0,0,i+1,line2[j].fi-line1[i].fi,line1[i].se,j),dfs(0,0,i+1,0,0,j+1));
				else if (line1[i].fi > line2[j].fi)
					return line2[j].fi+max(dfs(line1[i].fi-line2[j].fi,line1[i].se,i,0,0,j+1),dfs(0,0,i+1,0,0,j+1));
				else
					return line1[i].fi+dfs(0,0,i+1,0,0,j+1);
			}
			else
				return max(dfs(0,0,i+1,0,0,j),dfs(0,0,i,0,0,j+1));
		}
	}
	else
		return 0;
}

int main()
{
	scanf("%d",&t);
	FORN(i,t)
	{
		scanf("%d%d",&n,&m);
		FORN(j,n)
			scanf("%lld%d",&line1[j].fi,&line1[j].se);
		FORN(j,m)
			scanf("%lld%d",&line2[j].fi,&line2[j].se);
		printf("Case #%d: %lld\n",i+1,dfs(0,0,0,0,0,0));
	}
}
