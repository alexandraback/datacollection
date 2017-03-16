#include<stdio.h>
#include<string.h>
#include<map>
#include<iostream>
using namespace std;
map<char,char>mp;
map<char,char>::iterator ll,rr;
char a[10][10000];
char b[10][10000];
bool is[30];
void init()
{
//	for(int i=0;i<3;i++)
//		gets(a[i]);
//	for(int i=0;i<3;i++)
//		gets(b[i]);
//	mp.clear();
//	mp['q']='z';
//	memset(is,false,sizeof(is));
//	is['z'-'a']=true;
//	for(int i=0;i<3;i++)
//	{
//		int len=strlen(a[i]);
//		for(int j=0;j<len;j++)
//		{
//			if(a[i][j] >= 'a' && a[i][j] <= 'z')
//			{
//				is[b[i][j]-'a']=true;
//				mp[a[i][j]]=b[i][j];
//			}
//		}
//	}
//	for(int i=0;i<26;i++)
//		if(!is[i])
//			mp['z']='a'+i;
//	mp[' ']=' ';
//	for(ll=mp.begin(),rr=mp.end();ll!=rr;ll++)
//		printf("mp['%c']='%c';\n",ll->first,ll->second);
	mp[' ']=' ';
	mp['a']='y';
	mp['b']='h';
	mp['c']='e';
	mp['d']='s';
	mp['e']='o';
	mp['f']='c';
	mp['g']='v';
	mp['h']='x';
	mp['i']='d';
	mp['j']='u';
	mp['k']='i';
	mp['l']='g';
	mp['m']='l';
	mp['n']='b';
	mp['o']='k';
	mp['p']='r';
	mp['q']='z';
	mp['r']='t';
	mp['s']='n';
	mp['t']='w';
	mp['u']='j';
	mp['v']='p';
	mp['w']='f';
	mp['x']='m';
	mp['y']='a';
	mp['z']='q';

}
char s[100010];
int main()
{
	init();
	int cas;
	scanf("%d",&cas);
	getchar();
	for(int cc=1;cc<=cas;cc++)
	{
		printf("Case #%d: ",cc);
		gets(s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
			printf("%c",mp[s[i]]);
		printf("\n");
	}
	return 0;
}

