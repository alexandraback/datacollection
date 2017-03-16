#include "stdio.h"

int heights[100][100];


int rows[100];
int cols[100];


int main(int argc,char *argv[])
{
	(void) argc;
	(void) argv;
	
	int numTests;
	
	scanf("%d", &numTests);
	
	
	for(int i = 0;i < numTests;i++)
	{
		int N;
		int M;
		
		bool possible = true;
		
		scanf("%d %d", &N, &M);
		for(int j = 0;j < N;j++)
		{
			for(int k = 0;k < M;k++)
			{
				scanf("%d", &(heights[j][k]));
			}
		}
		
		//find the lowest height for each row that would work
		for(int j = 0;j < N;j++)
		{
			rows[j] = 0;
			for(int k = 0;k < M;k++)
			{
				if(heights[j][k] > rows[j])
				{
					rows[j] = heights[j][k];
				}
			}
		}
		
		//find the lowest height for each coll that would work
		for(int j = 0;j < M;j++)
		{
			cols[j] = 0;
			for(int k = 0;k < N;k++)
			{
				if(heights[k][j] > cols[j])
				{
					cols[j] = heights[k][j];
				}
			}
		}
		
		for(int j = 0;j < N;j++)
		{
			for(int k = 0;k < M;k++)
			{
				if(heights[j][k] != rows[j] && heights[j][k] != cols[k])
				{
					possible = false;
					break;
				}
			}
			if(!possible)
			{
				break;
			}
		}
		
		
		printf("Case #%d: ", i+1);
		if(possible)
		{
			printf("YES");
		}
		else
		{
			printf("NO");
		}
		printf("\n");
	}
	
	return 0;
}


