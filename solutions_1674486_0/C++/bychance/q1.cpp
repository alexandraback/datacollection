#include "stdio.h"
#include "vector"
using namespace std;

const int N=1010;
vector<int> linkl[N];
int n;
bool visit[N],is_ok,v2[N];

void dfs(int x)
{
	if(is_ok) return;
	if(v2[x])
	{
		is_ok=true;
		return;
	}
	v2[x]=true;
	for(int i=0;i<linkl[x].size() && !is_ok;i++)
	{
		dfs(linkl[x][i]);
	}
}

int main()
{
	freopen("A-small-attempt0 (2).in","r",stdin);
	freopen("out.txt","w",stdout);
	int cases,cnt=0;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		int x,num;
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;i++){
			linkl[i].clear();
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&x);
				linkl[i].push_back(x-1);
				visit[x-1]=true;
			}
		}
		is_ok=false;
		for(int i=0;i<n&&!is_ok;i++)
		{
			if(!visit[i])
			{
				memset(v2,0,sizeof(v2));
				dfs(i);
			}
		}
		if(is_ok) printf("Case #%d: Yes\n",++cnt);
		else printf("Case #%d: No\n",++cnt);
	}
	return 0;
}