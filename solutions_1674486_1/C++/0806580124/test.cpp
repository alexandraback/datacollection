#include <iostream>
#include <vector>
using namespace std;
bool f[1005];
int d[1005];
vector <int> map[1005];
int ok;
void dfs(int x)
{
	int i,j,k;
	if (ok==1)
		return;
	if (f[x]==1)
	{
		ok=1;
		return;
	}
	f[x]=1;
	for (i=0;i<map[x].size();i++)
		dfs(map[x][i]);
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,x,co=1;
	int n,t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			map[i].clear();
		memset(d,0,sizeof(d));
		for (i=0;i<n;i++)
		{
			scanf("%d",&k);
			for (j=0;j<k;j++)
			{
				scanf("%d",&x);
				x--;
				map[i].push_back(x);
				d[x]++;
			}
		}
		ok=0;
		for (i=0;i<n;i++)
			if (d[i]==0)
			{
				memset(f,0,sizeof(f));
				dfs(i);
				if (ok==1)
					break;
			}
		if (ok==1)
			printf("Case #%d: Yes\n",co++);
		else
			printf("Case #%d: No\n",co++);
	}
	return 0;
}
