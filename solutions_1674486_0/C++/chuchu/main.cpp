#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool dfs(bool arr[51][51],int m,int n,bool check[51])
{
	for(int i=1;i<=n;i++)
	{
		if(arr[m][i]==0||m==i)continue;
		if(check[i])return 1;
		check[i]=1;
		if(dfs(arr,i,n,check))return 1;
	}return 0;
}
int main()
{
	int cnt;scanf("%d",&cnt);
		for(int i=1;i<=cnt;i++)
		{
			int n; scanf("%d",&n);
			bool arr[51][51]={0};
			bool tmp[51]={0};
			for(int j=1;j<=n;j++)
			{
				int m; scanf("%d",&m);
				for(int k=0;k<m;k++)
				{
					int t; scanf("%d",&t);
					arr[j][t]=1;
				}
			}
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(j==k||arr[j][k]==0) continue;
					tmp[k]=1;
				}
			} bool cc=0;
			for(int j=1;j<=n;j++)
				if(tmp[j]==0){
					bool check[51]={0};
					cc|=dfs(arr,j,n,check);
				}
			if(cc)printf("Case #%d: Yes\n",i);
			else printf("Case #%d: No\n",i);
		}

}
