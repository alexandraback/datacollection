#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *in, *out;
	char s[128] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	char r[128] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	char letter[26];
    int i, j;
    int t;
	char G[30][101], cChar;
	in=fopen("A-small-attempt1.in", "r");
	out=fopen("out.txt", "w");
	for(j = 0; j < strlen(s); j++)
	{
		if(s[j]!= ' ')
		letter[s[j]-97]=r[j];
	}
	letter['z'-97] = 'q';
	letter['q'-97] = 'z';
	fscanf(in, "%d\n", &t);
	for(j=0;j<t;j++)
	{
		i=0;
		cChar=fgetc(in); 
		while(cChar!= '\n'&&!feof(in))  
		{  
			G[j][i]=cChar;
			i++;
			cChar=fgetc(in);  
		}
		G[j][i] = '\0';
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<strlen(G[i]);j++)
		{
			if(G[i][j]!= ' ')
			{
				G[i][j]=letter[G[i][j]-97];
			}
		}
		fprintf(out, "Case #%d: %s\n", i+1, G[i]);
	}
	fclose(in);
	fclose(out);
	return 0;
}

