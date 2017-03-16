#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool dfs(int arr[1001][11],int m,bool check[1001])
{
	for(int i=1;i<=arr[m][0];i++)
	{
		if(check[arr[m][i]])return 1;
		check[arr[m][i]]=1;
		if(dfs(arr,arr[m][i],check))return 1;
	}return 0;
}
int main()
{
	int cnt;scanf("%d",&cnt);
		for(int i=1;i<=cnt;i++)
		{
			int n; scanf("%d",&n);
			int arr[1001][11];
			bool tmp[1001]={0};
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&arr[j][0]);
				for(int k=1;k<=arr[j][0];k++)
				{
					scanf("%d",&arr[j][k]);
					tmp[arr[j][k]]=1;
				}
			}
			bool cc=0;
			for(int j=1;j<=n;j++)
				if(tmp[j]==0){
					bool check[1001]={0};
					cc|=dfs(arr,j,check);
				}
			if(cc)printf("Case #%d: Yes\n",i);
			else printf("Case #%d: No\n",i);
		}

}
