#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int hash[400];
void getHash()
{

	char org[3][100] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	char res[3][100] = {"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"};
	memset(hash,0,sizeof(hash));

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; org[i][j]; j++)
		{
			if (hash[org[i][j]] && hash[org[i][j]] != res[i][j] && org[i][j] != ' ')
				printf("error");
			hash[org[i][j]] = res[i][j];
		}
	}
	hash['q'] = 'z';
	hash['z'] = 'q';

	
}
int main()
{
	char s[101];
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	getHash();
	gets(s);
	for(int i = 1; i <= cas; i++)
	{
		gets(s);
		printf("Case #%d: ", i);
		for(int j = 0; s[j]; j++)
		{
			printf("%c", hash[s[j]]);
		}
		printf("\n");
	}
}