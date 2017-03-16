#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
char sw[128];
string s[6];
char ss[1000];
int main(void)
{
	sw['z']='q';
	sw['q']='z';
	s[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";	
	s[1]="our language is impossible to understand";
	s[2]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	s[3]="there are twenty six factorial possibilities";
	s[4]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	s[5]="so it is okay if you want to just give up";
	for(int i=0;i<s[0].size();i++)
	{
		sw[s[0][i]]=s[1][i];
	}
	for(int i=0;i<s[2].size();i++)
	{
		sw[s[2][i]]=s[3][i];
	}
	for(int i=0;i<s[3].size();i++)
	{
		sw[s[4][i]]=s[5][i];
	}
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T,g=0;
	scanf("%d\n",&T);
	while(T--)
	{
		gets(ss);
		printf("Case #%d: ",++g);
		int len=strlen(ss);
		for(int i=0;i<len;i++)
		{
			printf("%c",sw[ss[i]]);
		}
		printf("\n");
	}
	return 0;
}
