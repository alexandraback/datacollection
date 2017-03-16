#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 105;
char str[MAXN];

char let[] = {'y','h','e','s','o','c','v','x','d','u','i','g',
			'l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	int testcase;
	scanf("%d\n",&testcase);
	for(int t = 1; t <= testcase; t ++)
	{
		printf("Case #%d: ",t);
		gets(str);
		int len = strlen(str);
		for(int i = 0; i < len; i ++)
		{
			if(isalpha(str[i])) printf("%c",let[str[i]-'a']);
			else printf("%c",str[i]);
		}
		printf("\n");
	}
}
