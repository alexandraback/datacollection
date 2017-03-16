#include<stdio.h>
int visitdfs(int m[][1005],int d[],int v,int n)
{
	int temp,i;
	for(i=0;i<n;i++)
	{
		if(m[v][i]==1)
		{
			if(d[i]!=d[v])
			{
				d[i]=d[v];
				temp=visitdfs(m,d,i,n);
				if(temp==1)
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int count,error,Test,t,d[1005],temp2,n,m[1005][1005],i,j,temp;
	scanf("%d",&Test);
	for(t=0;t<Test;t++)
	{
		for(i=0;i<1005;i++)
		{
			d[i]=-1;
			for(j=0;j<1005;j++)
			{
				m[i][j]=0;
			}
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp2);
			for(j=0;j<temp2;j++)
			{
				scanf("%d",&temp);
				m[i][temp-1]=1;
			}
		}
		error=0;
		count=0;
		for(i=0;i<n;i++)
		{
			if(d[i]==-1)
			{
				d[i]=count;
				count++;
				if(visitdfs(m,d,i,n)==1)
				{
					error=1;
					break;
				}
			}
		}
		if(error==1)
		{
			printf("Case #%d: Yes\n",t+1);
		}
		else
		{
			printf("Case #%d: No\n",t+1);
		}
	}
	return 0;
}
