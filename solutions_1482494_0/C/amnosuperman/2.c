#include <stdio.h>
#include <stdlib.h>

typedef struct game_
{
	int zero;
	int one;
}game;

int compar(const void* a1,const void* b1)
{
	game* a = (game*)a1;
	game* b = (game*)b1;
	if(a->one<b->one)
		return -1;
	else if(a->one>b->one)
		return 1;
	else
	{
		if(a->zero<b->zero)
			return -1;
		else if(a->zero>b->zero)
			return 1;
		else
			return 0;
	}
}

int result(game* games, int n)
{

	int i,j;
	int* check = (int *)malloc(n*sizeof(int));
	int last = -1;
	int lastz = -1;
	
	for(i=0;i<n;i++)
		check[i] = 0;
		
	int score = 0;
	int pscore = 0;
	int count = 0;

	while(last<n-1)
	{
		if(score>=games[last+1].one)
		{
			score = score + 2;
			last++;
			count++;
			check[last] = 2;	
		}
		else
		{
			j=lastz+1;
			while(j<n)
			{
				if((check[j]==0) && (score>=games[j].zero))
				{
					count++;
					score++;
					check[j] = 1;
					lastz = j;
					break;
				}
				j++;
			}
		}
		if(score==pscore)
		{
			count = -1;
			break;
		}	
		else
			pscore = score;
	}
	
	return count;
}

int main()
{

	int t,n,a,b;
	scanf("%d",&t);
	
	int i,j,k;
	int res;
	
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
		
		game* games = (game*)malloc(n*sizeof(game));
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&games[i].zero);
			scanf("%d",&games[i].one);
		}
		
		qsort(games,n,sizeof(game),&compar);
		res = result(games,n);
		
		if(res!= -1)
			printf("Case #%d: %d\n",j+1,res);
		else
			printf("Case #%d: Too Bad\n",j+1);
		
	}
	
	return 0;
}
