#include<stdio.h>

#define MAX 10

bool CanMake(int lawn[][MAX], int r, int c)
{
	bool freerow[MAX];
	bool freecol[MAX];
	for(int i=0;i<r;i++)
	{
		freerow[i]=true;
		for(int j=0;j<c;j++)
			if(lawn[i][j]==2)
				freerow[i]=false;
	}
	for(int i=0;i<c;i++)
	{
		freecol[i]=true;
		for(int j=0;j<r;j++)
			if(lawn[j][i]==2)
				freecol[i]=false;
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(lawn[i][j]==1)
			{
				if(!freerow[i] && !freecol[j])
					return false;
			}
		}
	}
	return true;
}

int main()
{
	int lawn[MAX][MAX];
	int T, r, c;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d %d",&r,&c);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				scanf("%d",&lawn[i][j]);
		if(CanMake(lawn,r,c)) printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}
	return 0;
}