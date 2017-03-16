#include <iostream>
using namespace std;

char tmp[26]={'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'};
char tra[26];
void init()
{
	char x;
	for(int i=0;i<26;i++)
	{
		x=tmp[i];
		tra[x-'a']='a'+i;
	}
}
int main()
{
	char str[200];
	int T;
	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	init();
	scanf("%d",&T);
	gets(str);
	for(int cnb=1;cnb<=T;cnb++)
	{
		gets(str);
		char *p=str;
		for(;*p;p++)
		{
			if('a'<=*p && *p<='z')
				*p=tra[*p-'a'];
		}
		printf("Case #%d: %s\n",cnb,str);
	}
}