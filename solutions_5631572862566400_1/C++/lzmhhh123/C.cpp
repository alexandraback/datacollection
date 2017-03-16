#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<list>
#define maxn 1010
using namespace std;
list<int>map[maxn],map1[maxn];
int p[maxn],vis[maxn],s[maxn];
int n;
int now,ans;
void DFS(int u,int step)
{
	vis[u]=now;
	s[u]=step;
	for(list<int>::iterator p=map[u].begin();p!=map[u].end();p++)
		if(!vis[*p])
			DFS(*p,step+1);
		else if(vis[*p]==now)
			ans=max(ans,step-s[*p]+1);
	return;
}
int find_maxstep(int u,int f,int pp)
{
	int ret=0;
	for(list<int>::iterator p=map1[u].begin();p!=map1[u].end();p++)
		if(*p!=f&&*p!=pp)
			ret=max(ret,find_maxstep(*p,u,pp));
	return ret+1;
}
int main()
{
	int T;
	cin>>T;
	for(int ii=1;ii<=T;++ii)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",p+i);
			map[i].push_back(p[i]);
			map1[p[i]].push_back(i);
		}
		printf("Case #%d: ",ii);
		for(int i=1;i<=n;++i)
			if(!vis[i])
			{
				now=i;
				vis[i]=i;
				DFS(i,0);
			}
		int sum=0;
		for(int i=1;i<=n;++i)
			if(p[i]>i&&p[p[i]]==i)
			{
				int tmp1=find_maxstep(i,0,p[i]),tmp2=find_maxstep(p[i],0,i);
				sum+=tmp1+tmp2;
			}
		ans=max(ans,sum);
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)
		{
			map[i].clear();
			map1[i].clear();
		}
		memset(vis,0,sizeof vis);
		ans=0;now=0;
		memset(s,0,sizeof s);
	}
	return 0;
}