#include<stdio.h>
int main()
{
	int ar[105][105],n,m,t,i,j,max,flag,k=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		flag=0;
		for(i=0;i<n;i++)
		{	
			max=-1;
			for(j=0;j<m;j++)
			{
				scanf("%d",&ar[i][j]);
				if(ar[i][j]>max)
					max=ar[i][j];
			}
			ar[i][m]=max;
		}
		for(j=0;j<m;j++)
		{	
			max=-1;
			for(i=0;i<n;i++)
			{
				if(ar[i][j]>max)
					max=ar[i][j];
			}
			ar[n][j]=max;
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(ar[i][j]!=ar[i][m] && ar[i][j]!=ar[n][j])
				{
					flag=1;
					break;
				}
		printf("Case #%d: ",k++);
		if(!flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
		