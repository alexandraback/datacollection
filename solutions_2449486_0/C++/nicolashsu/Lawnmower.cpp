#include "stdio.h"
#include "stdlib.h"

int lawn[100][100];
int row[100],col[100];

int main()
{
	int T;
	int N,M;
	int i,j;
	int t=1;
	int flag;
	scanf("%d",&T);
	while(t<=T)
	{
		scanf("%d%d",&N,&M);
		flag=1;
		for(i=0;i<N;i++)
			row[i]=0;
		for(j=0;j<M;j++)
			col[j]=0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				scanf("%d",&lawn[i][j]);
				if(lawn[i][j]>row[i])row[i]=lawn[i][j];
				if(lawn[i][j]>col[j])col[j]=lawn[i][j];
			}
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				if(lawn[i][j]!=row[i]&&lawn[i][j]!=col[j])
				{
					flag=0;
					break;
				}
			}
			if(flag==0)break;
		}
		switch(flag)
		{
			case 0: printf("Case #%d: NO\n",t);
					break;
			case 1: printf("Case #%d: YES\n",t);
					break;
		}
		t++;
	}
	return 0;
}