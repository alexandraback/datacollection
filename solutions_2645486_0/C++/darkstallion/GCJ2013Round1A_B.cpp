//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<set>
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
#define PI 3.1415926535897932384626433832795
#define eps 1e-9
using namespace std;

int v[10],e,r,n,ans;

void dfs(int qt,int i,int x)
{
	if (i == n)
		ans = max(ans,x);
	else
		FORS(j,0,qt)
			dfs(min(e,qt-j+r),i+1,x+v[i]*j);
}

int main()
{
	int t;
	scanf("%d",&t);
	FORN(i,t)
	{
		scanf("%d%d%d",&e,&r,&n);
		RES(v,0);
		FORN(j,n)
			scanf("%d",&v[j]);
		ans = 0;
		dfs(e,0,0);
		printf("Case #%d: %d\n",i+1,ans);
	}
}
