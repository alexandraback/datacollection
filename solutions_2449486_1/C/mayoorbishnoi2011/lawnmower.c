#include<stdio.h>
int main()
{
	int t,arr[100][100],i,j,flag,num=1,n,m,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				{
					scanf("%d",&arr[i][j]);
					if(arr[i][j] == 100)
						arr[i][j]=-100;
				}
		for(k=99;k>=1;k--)
		{
			for(i=0;i<n;i++)
			{	
				flag=0;
				for(j=0;j<m;j++)
					if(arr[i][j] < -k)
					{
						flag=1;
						break;
					}
				if(flag == 0)
					for(j=0;j<m;j++)
						if(arr[i][j] == k)
						arr[i][j]=-k;
						
			}
			for(j=0;j<m;j++)
			{
				flag=0;
				for(i=0;i<n;i++)
					if(arr[i][j] < -k)
					{
						flag=1;
						break;
					}
				if(flag == 0)
					for(i=0;i<n;i++)
						if(arr[i][j] == k)
						arr[i][j]=-k;
			
			}
			//printf("%d\n",k);
		}
		/*for(i=0;i<n;i++,printf("\n"))
			for(j=0;j<m;j++)
				printf("%d ",arr[i][j]);*/
		flag=0;
		for(i=0;i<n;i++)
		{	
			for(j=0;j<m;j++)
			{
				if(arr[i][j]>0)
				{
					flag=1;
					break;
				}
			}
			if(flag == 1)
				break;
		}
		
		if(flag == 0)
			printf("Case #%d: YES\n",num);
		else
			printf("Case #%d: NO\n",num);
		num++;
	}
	return 0;
}
