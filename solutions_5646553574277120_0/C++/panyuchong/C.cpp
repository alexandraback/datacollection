#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;

int T,Case,C,D,V,i,j,k,ans;
long long now,aim;
bool ban[100];

map <long long,int> Hash[105];

void dfs(int x,int y,long long z)
{
	if(Hash[x].find(z)!=Hash[x].end())
	{
		if(y>Hash[x][z])return;
	}
	Hash[x][z]=y;
	if(y>=ans)return;
	if(z==aim){ans=y;return;}
	if(x>V)return;
	dfs(x+1,y,z);
	if(!ban[x])
	{
		long long q=z|((z<<x)&aim);
		if(q!=z)dfs(x+1,y+1,q);
	}
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d%d",&C,&D,&V);
		aim=(1<<(V+1))-1;
		now=1;
		memset(ban,false,sizeof(ban));
		for(;D;--D)
		{
			scanf("%d",&k);
			ban[k]=true;
			now=now|((now<<k)&aim);
		}
		ans=10000;
		for(i=1;i<=V;++i)Hash[i].clear();
		dfs(1,0,now);
		++Case;
		printf("Case #%d: %d\n",Case,ans);
	}
}
