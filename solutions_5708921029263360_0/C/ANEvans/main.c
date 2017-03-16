#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	const int JP = 0;
	const int JS = 1;
	const int PS = 2;
	const int MAX = 12;
	
	int ndata;
	scanf("%d", &ndata);
	
	for (int asdf = 0; asdf < ndata; asdf++)
	{
		int j, p, s, k;
		scanf("%d %d %d %d", &j, &p, &s, &k);
		
		// create a counts array to track usages
		int*** counts = (int***)malloc(sizeof(int**) * 3);
		for (int i = 0; i < 3; i++)
		{
			counts[i] = (int**)malloc(sizeof(int*) * MAX);
			for (int k = 0; k < MAX; k++)
			{
				counts[i][k] = (int*)calloc(sizeof(int), MAX);
			}
		}
		
		// brute force it since each limit <= 10
		printf("Case #%d: ", asdf+1);
		
		// calculate the number of possibilities
		int outfits = 0;
		int last = 0;
		int temp = 0;
		int foundTemp = -1;
		
		for (int a = 0; a < j; a++)
		{
			for (int b = 0; b < p; b++)
			{
				foundTemp = -1;
				
				for (int c = 0; c < s; c++)
				{
					temp = (last + c) % s;
					if ((counts[PS][b][temp] < k) &&
						(counts[JP][a][b] < k) &&
						(counts[JS][a][temp] < k))
					{
						counts[JP][a][b]++;
						counts[JS][a][temp]++;
						counts[PS][b][temp]++;
						outfits++;
						foundTemp = temp;
					}
				}
				
				if (foundTemp >= 0)
				{
					last = foundTemp;
				}
			}
		}
		
		printf("%d\n", outfits);
		
		// clear the list
		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < MAX; b++)
			{
				for (int c = 0; c < MAX; c++)
				{
					counts[a][b][c] = 0;
				}
			}
		}
		
		// print the combos
		last = 0;
		temp = 0;
		foundTemp = -1;
		
		for (int a = 0; a < j; a++)
		{
			for (int b = 0; b < p; b++)
			{
				foundTemp = -1;
				
				for (int c = 0; c < s; c++)
				{
					temp = (last + c) % s;
					if ((counts[PS][b][temp] < k) &&
						(counts[JP][a][b] < k) &&
						(counts[JS][a][temp] < k))
					{
						counts[JP][a][b]++;
						counts[JS][a][temp]++;
						counts[PS][b][temp]++;
						foundTemp = temp;
						
						printf("%d %d %d\n", a+1, b+1, temp+1);
					}
				}
				
				if (foundTemp >= 1)
				{
					last = foundTemp;
				}
			}
		}
		
		// memory management
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < MAX; k++)
			{
				free(counts[i][k]);
			}
			free(counts[i]);
		}
		free(counts);
	}
	
	return 0;
}








