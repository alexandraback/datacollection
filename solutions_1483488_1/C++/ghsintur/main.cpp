
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>


FILE * fout;


 unsigned int calc(unsigned int a, unsigned int limit, unsigned int numOfdig, unsigned int numOfdigMod)
 {
 	unsigned int res=0;
 	unsigned int i;
 	unsigned int temp;
 	unsigned int toAdd;
 	unsigned int l = a;
 	for (i=0; i<numOfdig-1; i++)
 	{
 		temp	= a%numOfdigMod;
 		toAdd	= (a-temp)/numOfdigMod;
 		a		= (temp*10)+toAdd;
 		if((a > l) && (a <= limit))
 		{
 			res++;
 		}
		else if (a==l)
		{
			break;
		}
 	}
 	
 	return res;
 }

unsigned int calcNumOfDig(unsigned int num)
{
	unsigned int i;
	
	for (i=0; num>0 ;i++)
	{
		num = num/10;
	}
	
	return i;
}
void calcAll(unsigned int l, unsigned int h)
{
	unsigned int i;
	unsigned int j;
	unsigned int res = 0;
	unsigned int numOfDig = calcNumOfDig(h);
	unsigned int numOfDigPow = (unsigned int)pow((double)10, (double)numOfDig-1); 
	for(i=l; i<h;i++)
	{
		res = res + calc(i, h, numOfDig, numOfDigPow);	
	}
	fprintf(fout, "%d\n", res);
}

// void translate(unsigned int n, unsigned int m)
// {
// 	unsigned int res = 0;
// 
// 	
// 	fprintf(fout, "%d", res);
// 	fprintf(fout, "\n");
// }
// void RunTest(char* buffer)
// {
// 	unsigned int	numOfGog;
// 	unsigned int	numOfSup;
// 	unsigned int	resultToPass;
// 	char*			tok;
// 	unsigned int	i=0;
// 
// 	tok = strtok (buffer," ");
// 	numOfGog = atoi(tok);
// 	tok		= strtok (NULL, " ");
// 	numOfSup = atoi((tok));
// 	tok		= strtok (NULL, " ");
// 	resultToPass= atoi(tok);
// 	tok		= strtok (NULL, " ");
// 	while(NULL != tok)
// 	{
// 		gArr[i]	= atoi(tok);
// 		tok		= strtok (NULL, " ");
// 		i++;
// 	}
// 
// }



void main()
{
	FILE*			fin = NULL;
	int				rounds;
	int				i;
	unsigned		int l;
	unsigned		int h;
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
			sscanf(buffer, "%d %d", &l, &h);
			calcAll(l, h);
			memset(buffer, 0, 200);
		}

		fclose(fin);
		fclose(fout);
	}
}