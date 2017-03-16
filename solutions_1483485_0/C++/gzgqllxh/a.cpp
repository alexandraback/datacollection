#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<char,char>dic;
void init()
{
	dic.clear();
	dic['a']='y';
	dic['b']='h';
	dic['c']='e';
	dic['d']='s';
	dic['e']='o';
	dic['f']='c';
	dic['g']='v';
	dic['h']='x';
	dic['i']='d';
	dic['j']='u';
	dic['k']='i';
	dic['l']='g';
	dic['m']='l';
	dic['n']='b';
	dic['o']='k';
	dic['p']='r';
	dic['q']='z';
	dic['r']='t';
	dic['s']='n';
	dic['t']='w';
	dic['u']='j';
	dic['v']='p';
	dic['w']='f';
	dic['x']='m';
	dic['y']='a';
	dic['z']='q';
}
int main()
{
	init();
	char text[400];
	int tcase,casenum=0,i;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&tcase);
	getchar();
	while(tcase--)
	{
		gets(text);
		printf("Case #%d: ",++casenum);
		for(i=0;text[i];i++)
		{
			if('a'<=text[i]&&text[i]<='z')
			{
				cout<<dic[text[i]];
				//printf('%c',dic[text[i]]);
			}
			else
				cout<<text[i];
		}
		printf("\n");
	}
	return 0;
}
