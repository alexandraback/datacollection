#include<stdio.h>
#include<string.h>

int main()
{
	char cc[26];
	char s[128]="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	char r[128]="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	int i,j;
	for(j=0;j<strlen(s);j++)
	{
		if(s[j]!=' ')
		cc[s[j]-97]=r[j];
	}
	cc['z'-97]='q';
	cc['q'-97]='z';
	int T;
	char G[30][101],cChar;
	FILE *in,*out;
	in=fopen("A-small-attempt0.in","r");
	out=fopen("1ou.txt","w");
	fscanf(in,"%d\n",&T);
	for(j=0;j<T;j++)
	{
		i=0;
		cChar=fgetc(in); 
		while(cChar!='\n'&&!feof(in))  
		{  
			G[j][i]=cChar;
			i++;
			cChar=fgetc(in);  
		}
		G[j][i]='\0';
	}
	fclose(in);
	for(i=0;i<T;i++)
	{
		for(j=0;j<strlen(G[i]);j++)
		{
			if(G[i][j]!=' ')
			{
				G[i][j]=cc[G[i][j]-97];
			}
		}
		fprintf(out,"Case #%d: %s\n",i+1,G[i]);
	}
	fclose(out);
	return 0;
}

