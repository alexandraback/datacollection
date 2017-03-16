
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>


char arrAbc []		= "abcdefghijklmnopqrstuvwxyz";
char arrGog	[]		= "yhesocvxduiglbkrztnwjpfmaq"; 

char str1 []= "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyqeez";
char str2 []= "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupazooq";
// 
// void RunTest(char* buffer, unsigned int* arr)
// {
// 	char* tok;
// 	unsigned int i=0;
// 	tok = strtok (buffer," ");
// 	
// 	while(NULL != tok)
// 	{
// 		arr[i] = atoi(tok);
// 		tok			= strtok (NULL, " ");
// 		i++;
// 	}
// }
FILE * fout;
void translate(char* str, int length)
{
	int i;
	char c;

	for (i=0; i< length-1; i++)
	{
		c = str[i];
		fprintf(fout ,"%c", (c ==' '? ' ': arrGog[c-'a']));
	}
	fprintf(fout, "\n");
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
			translate(buffer, strlen(buffer));
			memset(buffer, 0, 200);
		}

		fclose(fin);
		fclose(fout);
	}

}