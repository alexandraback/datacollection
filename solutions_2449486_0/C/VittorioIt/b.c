#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lawn[100][100];
int N,M;

int maxRow(int i)
{
	int max=0;
	int j;
	for(j=0;j<M;j++)
	if (lawn[i][j] > max)
	max=lawn[i][j];
	
	return max;
}

int maxColumn(int i)
{
	int max=0;
	int j;
	for(j=0;j<N;j++)
	if (lawn[j][i] > max)
	max=lawn[j][i];
	
	return max;
}

void printCase(int i)
{
	printf("Case #%d: ",i+1);
}

int main()
{
	int cases,i;
	int maxr[100],maxc[100];
	scanf("%d",&cases);
	for(i=0;i<cases;i++)
	{
		int ans=1;
		int k,j;
		scanf("%d",&N);
		scanf("%d",&M);
		
		for(j=0;j<N;j++)
		for(k=0;k<M;k++)
		scanf("%d",&lawn[j][k]);
		
		
		for(j=0;j<N;j++)
		{
			maxr[j]=maxRow(j);
		}
		for(j=0;j<M;j++)
		{
			maxc[j]=maxColumn(j);
		}
		
		for(j=0;j<N;j++)
		{
			for(k=0;k<M;k++)
			{
				if(lawn[j][k]<maxr[j] && lawn[j][k]<maxc[k])
				{
					ans=0;
				}
			}
		}
		
		
		printCase(i);
		if(ans)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
