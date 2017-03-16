
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>


unsigned int gArr[200];
FILE * fout;
void translate(unsigned int* arr, int length, int num, int supNum)
{
	int i;
	int regCounter = 0;
	int supCounter = 0;
	int regMin = max(num*3 -2, num);
	int supMin = max(num*3 -4, num);

	for (i=0; i< length; i++)
	{
		if (arr[i]>=regMin)
		{
			regCounter++;
		}
		else if (arr[i] <= 1)
		{
			if (arr[i]>= num)
			{
				regCounter++;
			}
		}
		else if (arr[i]>=supMin)
		{
			supCounter++;
		}
	}

	supCounter = min(supCounter, supNum);
	fprintf(fout, "%d", supCounter+regCounter);
	fprintf(fout, "\n");
}
void RunTest(char* buffer)
{
	unsigned int	numOfGog;
	unsigned int	numOfSup;
	unsigned int	resultToPass;
	char*			tok;
	unsigned int	i=0;

	tok = strtok (buffer," ");
	numOfGog = atoi(tok);
	tok		= strtok (NULL, " ");
	numOfSup = atoi((tok));
	tok		= strtok (NULL, " ");
	resultToPass= atoi(tok);
	tok		= strtok (NULL, " ");
	while(NULL != tok)
	{
		gArr[i]	= atoi(tok);
		tok		= strtok (NULL, " ");
		i++;
	}

	translate(gArr,numOfGog, resultToPass, numOfSup);
}



void main()
{
	
	FILE*			fin = NULL;
	int				rounds;
	int				i;
	char			buffer [1024*8] = {0};
	fopen_s(&fin, "2.in", "r");
	fopen_s(&fout, "2.out", "w");
	if(fin)
	{
		fgets(buffer,1024*8, fin);
		sscanf(buffer, "%d",&rounds);

		for(i=0; i<rounds; i++)
		{
			fprintf(fout, "Case #%d: ",i+1);
			fgets(buffer,1024*8, fin);
			RunTest(buffer);
			memset(buffer, 0, 200);
		}

		fclose(fin);
		fclose(fout);
	}

}