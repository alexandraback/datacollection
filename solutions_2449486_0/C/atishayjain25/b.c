#include<stdio.h>

int main()
{
	int t,cases,n,m,i,j,ans;
	int board[20][20];
	int row[20], col[20];
	scanf("%d\n",&t);
	for(cases=1;cases<=t;cases++)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&board[i][j]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(board[i][j]==2)
					break;
			}
			if(j==m)
				row[i]=1;
			else
				row[i]=0;	
		}	
		
		for(j=0;j<m;j++)
		{
			for(i=0;i<n;i++)
			{
				if(board[i][j]==2)
					break;
			}
			if(i==n)
				col[j]=1;
			else
				col[j]=0;	
		}
		
		ans=1;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(board[i][j]==1)
				{
					if(!(row[i]==1 || col[j]==1))
						ans=2;
				}
			}
		if(ans==1)
			printf("Case #%d: YES\n",cases);	
		else if(ans==2)
			printf("Case #%d: NO\n",cases);						
	}
	return 0;
}
