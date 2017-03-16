#include<stdio.h>
#include<stdlib.h>

using namespace std;
int N,n;
int g[1005][1005],mark[1005][1005];

int main()
{
	int t,T;
	int i,j,k,M,v;
	int flag;
	system("ren *.in input.in");
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(t=1 ; t<=T ; t++)
	{
		scanf("%d",&N);
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				g[i][j] = mark[i][j] = 0;
		for(i=1 ; i<=N ; i++)
		{
			scanf("%d",&M);
			for(j=1 ; j<=M ; j++)
			{
				scanf("%d",&v);
				g[i][v] = 1;
				mark[i][v]++;
			}
			
		}
		for(i=1 ; i<=N ; i++)
			mark[i][i]++;
			/*
		for(i=1 ; i<=N ; i++)
		{
			for(j=1 ; j<=N ; j++)
				if(mark[i][j]==0)
					printf("! ");
					else
					printf("%d ",g[i][j]);
			puts("");
		}
		puts("");*/
		flag = 0;
		for(k=1 ; k<=N && !flag; k++)
			for(i=1 ; i<=N && !flag ; i++)
				for(j=1 ; j<=N && !flag ; j++)
				{
					if(mark[i][j] &&  g[i][k]>0 && g[k][j]>0)
					{
						flag = 1;
					}
					else if((!mark[i][j]) && g[i][k]>0 && g[k][j]>0)
					{
						mark[i][j]++;
						g[i][j] = g[i][k]+g[k][j];
					}
				}
		/*for(i=1 ; i<=N ; i++)
		{
			for(j=1 ; j<=N ; j++)
				if(mark[i][j]==0)
					printf("! ");
					else
					printf("%d ",g[i][j]);
			puts("");
		}*/
		printf("Case #%d: %s\n",t,flag ? "Yes":"No");
	}
	//for(;;);
	scanf(" ");
	return 0;
}
