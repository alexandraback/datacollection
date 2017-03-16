#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define N 110

int i, j, t, len;
char s[30] = {"yhesocvxduiglbkrztnwjpfmaq"};
char str[N];

int main()
{
	//FILE *fp1 = fopen("input.txt", "r");
	FILE *fp1 = fopen("A-small-attempt1.in", "r");
	FILE *fp2 = fopen("output.txt", "w");

	fscanf(fp1, "%d\n", &t);
	for(i = 1; i <= t; i++)
	{
		fgets(str, 105, fp1);
		
		fprintf(fp2, "Case #%d: ", i);
		len = strlen(str);
		for(j = 0; j < len-1; j++)
		{
			if(str[j] == ' ')
				fprintf(fp2, " ");
			else
				fprintf(fp2, "%c", s[str[j]-'a']);
		}
		fprintf(fp2, "\n");
	}

	fcloseall();
	return 0;
}