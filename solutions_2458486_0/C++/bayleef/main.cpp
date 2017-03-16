#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int,int>keys,m[30];
int t[30];
int i,j,k,l,n,T,ts;
vector<int>ans[2000000],tr;

int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&k,&n);
		keys.clear();
		for(i=0;i<k;i++)
		{
			scanf("%d",&j);
			keys[j]++;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&t[i],&k);
			m[i].clear();
			while(k--)
			{
				scanf("%d",&j);
				m[i][j]++;
			}
		}
		ans[0].clear();
		ans[0].push_back(-1);
		for(i=1;i<1<<n;i++)
		{
			ans[i].clear();
			for(j=0;j<n;j++)
			{
				if(!(i>>j&1) || ans[i^1<<j].empty())
					continue;
				l=keys[t[j]];
				for(k=0;k<n;k++)
					if(k!=j && (i>>k&1))
						l+=m[k][t[j]]-(t[k]==t[j]);
				if(l)
				{
					tr=ans[i^1<<j];
					tr.push_back(j);
					if(ans[i].empty() || ans[i]>tr)
						ans[i]=tr;
				}
			}
		}
		printf("Case #%d:",++ts);
		if(ans[(1<<n)-1].empty())
			puts(" IMPOSSIBLE");
		else
		{
			for(i=1;i<=n;i++)
				printf(" %d",ans[(1<<n)-1][i]+1);
			puts("");
		}
	}
	return 0;
}