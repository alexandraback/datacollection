/*
	Diamond_Inheritance.c - Google Code Jam
	By Yemeli TC - yemelitassecyrille@gmail.com - YTC_CCE

Information haved:
 - T = number of test cases
Information needed:
 - 
*/



// includes
#include<stdio.h>

#define maxN 50
#define maxM 10

int note, N, size_presence;
int presence[maxN];
int classes[maxN][maxM], M[maxN];

int search(int level);

int main()
{
	FILE *input, *output;
	input = fopen("A-small-attempt0.in", "r");
	output = fopen("A-small-attempt0.out", "w");

	int i, j, whcase, T;

	fscanf(input, "%d", &T); // get the number of test cases

	for(whcase=1; whcase<=T; whcase++)
	{
		fprintf(output, "Case #%d: ", whcase);
		printf("\n");
		N=0;
		for(i=0; i<maxN; i++) M[i]=0;

		// data collection
		fscanf(input, "%d", &N);

		for(i=0; i<N; i++)
		{
			fscanf(input, "%d", &M[i]);
			for(j=0; j<M[i]; j++)
			{	fscanf(input, "%d", &classes[i][j]);
				//printf("classes[%d][%d] = %d\n", i, j, classes[i][j]);
			}
		}

		// searching result
		note=0;
		for(i=0; i<N; i++)
		{
			size_presence=0;
			note = search(i);
			if(note) break;
			//printf("-----------next\n");
		}
		
		//outputing result
		if(note) fprintf(output, "Yes\n");
		else fprintf(output, "No\n");
	}
	fclose(input);
	fclose(output);
	return 0;
}

int search(int level)
{
	int i, j;
	//for(i=0; i<size_presence; i++) printf("[%d]=%d ", i, presence[i]); printf("                 level=%d\n", level);
	for(i=0; i<M[level]; i++)
	{
		for(j=0; j<size_presence; j++) if(presence[j]==classes[level][i]) return 1;
		presence[size_presence++]=classes[level][i];
		if( search(classes[level][i]-1)) return 1;
	}
	return 0;
}

