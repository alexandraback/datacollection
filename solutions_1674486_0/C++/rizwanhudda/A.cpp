#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<vector<int> > AL(1010);
int N;
bool vis[1010],diamond,p[1010];
void dfs(int v)
{
	vis[v]=1;
	for (int i=0;i<AL[v].size();i++)
		if (!vis[AL[v][i]])
		{
			//p[AL[v][i]]=v;
			dfs(AL[v][i]);
		} else 
		///if (p[v]!=AL[v][i])
		{
			diamond=1;
		}
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out2.txt","w",stdout);
    int T,M,tmp;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
		diamond=0;
        scanf("%d",&N);
		for (int i=0;i<N;i++)
			AL[i].clear();
		for (int i=0;i<N;i++)
		{
			scanf("%d",&M);
			for (int j=0;j<M;j++)
			{
				scanf("%d",&tmp);
				AL[i].push_back(tmp-1);
				//AL[tmp-1].push_back(j);
			}
			vis[i]=0;
		}
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
				vis[j]=0;
			dfs(i);
		}
		printf("Case #%d: ",t);
		if(diamond)printf("Yes\n");
		else printf("No\n");
    }
    return 0;
}

