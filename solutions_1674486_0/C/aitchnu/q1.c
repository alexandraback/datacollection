#include<stdio.h>
int main()
{
	int t,z=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",z);
		z++;
		int n;
		scanf("%d",&n);
		int arr[1001][1001];
		int i,j,k,m,temp,flag=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				arr[i][j]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&temp);
				arr[i][temp]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			int a[n+1],stack[1001],count=0;
			for(j=1;j<=n;j++)
				a[j]=0;
			for(j=1;j<=n;j++)
			{
				if(arr[i][j]==1)
				{
					a[j]=1;
					stack[count]=j;
					count++;
				}
			}
			for(j=0;j<count;j++)
			{
				for(k=1;k<=n;k++)
				{
					if(arr[stack[j]][k]==1)
					{
						if(a[k]==1)
						{
							flag=1;
							break;
						}
						else
						{
							a[k]=1;
							stack[count]=k;
							count++;
						}
					}
				}
				if(flag==1)
				{
//					for(i=0;i<count;i++)
//					printf("%d ",stack[i]);
//						printf("\n");
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

