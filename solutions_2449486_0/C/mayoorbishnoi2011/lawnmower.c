#include<stdio.h>
int main()
{
	int t,arr[10][10],i,j,flag,num=1,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				{
					scanf("%d",&arr[i][j]);
					if(arr[i][j] == 2)
						arr[i][j]=-2;
				}
		for(i=0;i<n;i++)
		{
			flag=0;
			for(j=0;j<m;j++)
				if(arr[i][j] == -2)
					flag=1;
			if(flag == 0)
				for(j=0;j<m;j++)
					arr[i][j]=-1;
						
		}
		for(j=0;j<m;j++)
		{
			flag=0;
			for(i=0;i<n;i++)
				if(arr[i][j] == -2)
					flag=1;
			if(flag == 0)
				for(i=0;i<n;i++)
					arr[i][j]=-1;
		
		}
		flag=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(arr[i][j]>0)
					flag=1;
		if(flag == 0)
			printf("Case #%d: YES\n",num);
		else
			printf("Case #%d: NO\n",num);
		num++;
	}
	return 0;
}
