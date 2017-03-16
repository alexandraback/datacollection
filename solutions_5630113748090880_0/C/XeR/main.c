#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define  MAX_HEIGHT 2500

void solve(size_t **list, size_t height, size_t width)
{
	size_t heights[MAX_HEIGHT];
	char   uniq   [MAX_HEIGHT];
	size_t i, j;
	
	bzero(heights, MAX_HEIGHT * sizeof(size_t));
	bzero(uniq,    MAX_HEIGHT * sizeof(char));
	
	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++)
			heights[list[i][j]]++;

	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++)
			if(heights[list[i][j]] & 1)
				uniq[list[i][j]] = 1;

	for(i = 0; i < MAX_HEIGHT; i++)
		if(uniq[i])
			printf("%llu ", i);

}

int main(int argc, char *argv[])
{
	size_t i, j, k;
	
	size_t T;
	size_t N;
	size_t max;
	
	size_t **list;
	
	scanf("%u", &T);
	
	for(i = 0; i < T; i++) {
		scanf("%llu", &N);
		max = (2 * N) - 1;
		
		list = calloc(max, sizeof(size_t));
		
		for(j = 0; j < max; j++) {
			list[j] = calloc(N, sizeof(size_t));
			
			for(k = 0; k < N; k++) {
				scanf("%llu", &list[j][k]);
			}
		}
		
		printf("Case #%u: ", i + 1);
		solve(list, max, N);
		printf("\n");
		
		for(j = 0; j < max; j++)
			free(list[j]);
		free(list);
	}
}