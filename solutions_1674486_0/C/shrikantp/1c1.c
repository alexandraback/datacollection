#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,i,j,k,n,adj[1000][1000],m,u,ans[50],flag,l;
scanf("%d",&t);
for(i=0;i<1000;i++)
{
	for(j=0;j<1000;j++)
	adj[i][j]=0;
}

for(k=0;k<t;k++)
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%d",&u);
			adj[i][u-1]=i+1;
			adj[u-1][i]=0;
		}
	}
	flag=0;
	for(l=0;l<n-2;l++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(adj[i][j]!=0)
				{
					for(m=0;m<n;m++)
					{
						if(adj[j][m]!=0)
						{
						//	printf("im %d jm %d\n",adj[i][m],adj[j][m]);
							if(adj[i][m]!=adj[j][m] && adj[i][m]!=0)
							{
								
								flag=1;
								break;
							}
							else
							{
								adj[i][m]=adj[j][m];
							}
						}
					}
					if(flag)
						break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			break;	
	}
	
	ans[k]=flag;	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		adj[i][j]=0;
	}

}
for(k=0;k<t;k++)
{
	if(ans[k]==1)
		printf("Case #%d: Yes\n",k+1);
	else
		printf("Case #%d: No\n",k+1);		
}
return 0;
}
