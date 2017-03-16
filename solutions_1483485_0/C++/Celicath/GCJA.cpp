#include<stdio.h>
/*
char line[200];
char mapper[] =
"abcdefghijklmnopqrstuvwxyz";
"i   o        b  z       a";가 위로 감.
/*/

char line[200];
char ques[] = "ynficwlbkuomxsevzpdrjgthaq";
char back[] = "                          ";
 
int main()
{
	int T;

	for(int i = 0; i < 26; i++)
	{
		back[ques[i]-'a'] = i+'a';
	}

	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt","w");

	fscanf(fin, "%d\n", &T);

	for(int i = 1; i <= T; i++)
	{
		fgets(line, 105,fin);
		for(int j = 0; line[j]; j++)
		{
			if(line[j] != ' ')
			{
				line[j] = back[line[j]-'a'];
			}
		}
		fprintf(fout,"Case #%d: %s\n", i, line);
	}
}
