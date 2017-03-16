//#include <algorithm>

//#include <cstdio>

//#include <cmath>

#include <algorithm>
#include <cstdio>
//#include <cstdlib>
#include <cstring>

//#include <cstring>
//#include <string>

//#include <iostream>

//#include <map>
//#include <utility>

//#include <vector>

using namespace std;

typedef long long int big;
int n,m,K;

int cnt(int x)
{
	int s=0;
	while(x)s++,x-=x&-x;
	return s;
}
inline int id(int x,int y)
{
	return (x-1)*m+y-1;
}
int sum=0;
int g[33][33];
int idx;
int vis[33][33];
void dfs(int x,int y)
{
	if(x<0||x>n+1||y<0||y>m+1)return ;
	if(vis[x][y]==idx||g[x][y])return;
	vis[x][y]=idx;
	if(x>=1&&y>=1&&x<=n&&y<=m)sum++;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.txt", "w", stdout);
	int cass,i,j,k,r,cas,c,a,b;
	scanf("%d",&cas);
	int ans;
	for(cass=1; cass<=cas;cass++) {
		printf("Case #%d: ",cass);
		scanf("%d%d%d",&n,&m,&K);
		memset(vis,0,sizeof(vis));
		memset(g,0,sizeof(g));
		idx=3;
		ans=2009;
		for(k=0;k<(1<<(n*m));k++)
			if(cnt(k)<ans)
			{
				idx++;
				for(i=1;i<=n;i++)
					for(j=1;j<=m;j++)
						g[i][j]=k>>id(i,j)&1;
				int tmp=cnt(k);
				sum=0;
				dfs(0,0);
				if(n*m-sum>=K)
					ans=min(ans,tmp);
			}
		printf("%d\n",ans);
	}
}
