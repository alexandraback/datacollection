#include "stdio.h"
#include "vector"
using namespace std;
#define N 1023
vector<vector<int> > Edge(N,vector<int>());
int n;
bool canflag;
vector<bool> visit(N),used(N);

void dfs(int x)
{
	if(canflag) return;
	if(used[x])
	{
		canflag=true;
		return;
	}
	used[x]=true;
	for(int i=0;!canflag && i<Edge[x].size() ;i++)
	{
		dfs(Edge[x][i]);
	}
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int caseN;
	scanf("%d",&caseN);
	for (int cs=1;cs<=caseN;cs++)
	{
		scanf("%d",&n);
		int x,c;
		visit.assign(visit.size(),0);
		for(int i=0;i<n;i++){
			Edge[i].clear();
			scanf("%d",&c);
			for (;c--;){
				scanf("%d",&x);
				x--;
				Edge[i].push_back(x);
				visit[x]=true;
			}
		}
		canflag=false;
		for(int i=0;i<n&&!canflag;i++)
		{
			if(!visit[i])
			{
				used.assign(used.size(),0);
				dfs(i);
			}
		}
		if(canflag) printf("Case #%d: Yes\n",cs);
		else printf("Case #%d: No\n",cs);
	}
	return 0;
}