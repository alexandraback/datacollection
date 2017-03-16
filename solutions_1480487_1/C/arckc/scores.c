#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[])
{
	FILE *input, *output;
	int in_size;
	int i, j, no_contestants;
	float total, *scores, score, min, *results, rem, count;
	char inc_p;
	input = fopen(argv[1],"rt");
	output = fopen("output.txt","w");
	if(input == NULL) return 0;
	fscanf(input,"%d",&in_size);
	for(i = 0; i<in_size; i++)//for each test case
	{
		total = 0;
		rem = 0;
		count = 0;
		fscanf(input, "%d",&no_contestants);
		scores = (float*)malloc(sizeof(float)*no_contestants);
		results = (float*)malloc(sizeof(float)*no_contestants);
		for(j = 0; j<no_contestants; j++)//for each contestant
		{

			fscanf(input, "%f",&score);
			total += score;//get the total
			scores[j] = score;
		}
		min = total*2 / (no_contestants);
		fprintf(output, "Case #%d: ",i+1);
		for(j=0; j<no_contestants; j++)//for each contestant
		{
			results[j] = (min - scores[j])*100/total;
			if(results[j]<0){
				rem += results[j]*-1;
				results[j] = 0;
				count++;
			}
		}
		for(j=0; j<no_contestants; j++)//for each contestant
		{
			if(results[j]>0)
			{
				results[j]-=rem/(no_contestants-count);
			}
			fprintf(output,"%.6f ", results[j]);
		}
		fprintf(output,"\n");
		free(scores);
	}
	fclose(output);
	fclose(input);
	return 1;
}
