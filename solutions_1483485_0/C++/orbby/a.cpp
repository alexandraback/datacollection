 //if you want,you can
#include<stdio.h>

char cipher[][100]={
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
char message[][100]={
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"
};

char map[26];
char have[26];
void init()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;cipher[i][j];j++)
		{
			if(cipher[i][j]!=' ')
			{
				map[cipher[i][j]-'a']=message[i][j];
				have[message[i][j]-'a']=1;
			}
		}
	}
	map[16]='z';
	map[25]='q';
}

char in[100];
int main()
{
	init();
	/*for(int i=0;i<26;i++)
	{
		printf("%d %c\n",i,map[i]);
		if(have[i]==0)
		{
			printf("fuck %c\n",'a'+i);
		}
	}*/
	freopen("a.out","w",stdout);
	int t;
	scanf("%d ",&t);
	for(int i=0;i<t;i++)
	{
		gets(in);
		printf("Case #%d: ",i+1); 
		for(int i=0;in[i];i++)
		{
			if(in[i]==' ')
			{
				printf(" ");
			}
			else
			{
				printf("%c",map[in[i]-'a']);
			}
		}
		printf("\n");
	}
}
