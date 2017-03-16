#include<cstdio>
#include<algorithm>
using namespace std;

char map[128];

void getmap()
{
	FILE *fin=fopen("map.txt","r");
	char u[3],v[3];
	for(int i=0;i<26;i++)
	{
		fscanf(fin,"%s%s%*lf",u,v);
		map[u[0]]=v[0];
	}
	fclose(fin);
}

void printtrans(char *s)
{
	for(;*s;s++)
	{
		if(*s>='a' && *s<='z') printf("%c",map[*s]);
		else printf("%c",*s);
	}
	printf("\n");
}

void output1()
{
	int t;
	char str[110];
	scanf("%d ",&t);
	while(t--)
	{
		gets(str);
		printf("%s\n",str);
		printtrans(str);
		printf("\n");
	}
}

void output2()
{
	int t;
	char str[110];
	scanf("%d ",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		gets(str);
		printtrans(str);
	}
}

int main()
{
	getmap();
	output2();
	return 0;
}

