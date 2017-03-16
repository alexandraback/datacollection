#include<stdio.h>

int main()
{
	int t,cases,n,m,i,j,ans,maxm;
	int board[120][120];
	int row_m[120], col_m[120];
	scanf("%d\n",&t);
	for(cases=1;cases<=t;cases++)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&board[i][j]);

		for(i=0;i<n;i++)
		{
			maxm=board[i][0];
			for(j=1;j<m;j++)
			{
				if(board[i][j]>maxm)
					maxm=board[i][j];
			}
			row_m[i]=maxm;
		}
		
		for(j=0;j<m;j++)
		{
			maxm=board[0][j];
			for(i=1;i<n;i++)
			{
				if(board[i][j]>maxm)
					maxm=board[i][j];
			}
			col_m[j]=maxm;
		}
		ans=1;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(!(board[i][j]==row_m[i] || board[i][j]==col_m[j]))
					ans=2;
			}
		
		if(ans==1)
			printf("Case #%d: YES\n",cases);	
		else if(ans==2)
			printf("Case #%d: NO\n",cases);						
	}
	return 0;
}
