#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define ZERO(X) memset(X,0,sizeof(X))
#define FOR(I,N) for (I=0;I<(N);++I)
#define REV(I,N) for (I=(N)-1;I>=0;--I)
#define FORK(I,K,N) for (I=(K);I<(N);++I)
#define REVK(I,K,N) for (I=(K);I>=0;--I)
#define pb push_back
#define sci(d) scanf("%d",&d)
#define scll(l) scanf("%lld",&l)
#define scull(l) scanf("%llu",&l)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int AXIS=32;

bool u[65][64];
int xx,yy;

void dfs (int n, int x, int y, double & ans, double add)
{
	if (n==0) return;
	if (y==0)
	{
		u[x][y]=true;
		if (x==xx && y==yy) ans+=add;
		dfs(n-1,AXIS,63,ans,add);
		u[x][y]=false;
		return;
	}
	if (y>=2 && u[x][y-2]==false)
	{
		dfs(n,x,y-1,ans,add);
		return;
	}
	if (u[x-1][y-1] && u[x+1][y-1])
	{
		u[x][y]=true;
		if (x==xx && y==yy) ans+=add;
		dfs(n-1,AXIS,63,ans,add);
		u[x][y]=false;
		return;
	}
	if (u[x-1][y-1]==false && u[x+1][y-1]==false)
	{
		if (y==1)
		{
			dfs(n,x,y-1,ans,add);
			return;
		}
		dfs(n,x-1,y-1,ans,add/2.0);
		dfs(n,x+1,y-1,ans,add/2.0);
		return;
	}
	if (u[x-1][y-1]==false) dfs(n,x-1,y-1,ans,add);
	if (u[x+1][y-1]==false) dfs(n,x+1,y-1,ans,add);
}

int main ()
{
	int j,t;
	sci(t);
	FOR(j,t)
	{
		int n;
		double ans=0.0;
		scanf("%d%d%d",&n,&xx,&yy);
		xx+=AXIS;
		ZERO(u);
		dfs(n,AXIS,63,ans,1.0);
		if (ans>1.0) ans=1.0;
		printf("Case #%d: %f\n",j+1,ans);
	}
	return 0;
}