#include<stdio.h>
int main()
{
	int grid[10][10];
	int N,M,ii=1,tc;
	scanf("%d",&tc);
	while(ii<=tc)
	{
level1:
		if(ii>tc)
			break;
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				scanf("%d",&grid[i][j]);
		int f1=0,f2=0;
		for(int i=0;i<N;i++)
		{
		  for(int j=0;j<M;j++)
		  {
			  f1=f2=0;
			  if(grid[i][j]==1)
			  {
			            for(int k=0;k<M;k++)
					    if(grid[i][k]!=1)
					    {
						    f1=1;
						    break;
					    }
				    for(int k=0;k<N;k++)
					    if(grid[k][j]!=1)
					    {
						    f2=1;
						    break;
					    }
			  }
			  if((f1+f2)==2)
			  {
                           printf("Case #%d: NO\n",ii);
			   ii++;
			   goto level1;

			  }
		  }
		}
		printf("Case #%d: YES\n",ii);
		ii++;
	}
}
