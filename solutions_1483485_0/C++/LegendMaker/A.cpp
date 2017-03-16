#include<cstdio>
#include<cstring>
#define maxn 110
char s[maxn];
int g[maxn];
void Init()
{
	memset(g,0,sizeof(g));
	g['a']='y';
	g['b']='h';
	g['c']='e';
	g['d']='s';
	g['e']='o';
	g['f']='c';
	g['g']='v';
	g['h']='x';
	g['i']='d';
	g['j']='u';
	g['k']='i';
	g['l']='g';
	g['m']='l';
	g['n']='b';
	g['o']='k';
	g['p']='r';
	g['q']='z';
	g['r']='t';
	g['s']='n';
	g['t']='w';
	g['u']='j';
	g['v']='p';
	g['w']='f';
	g['x']='m';
	g['y']='a';
	g['z']='q';
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int i,c,ca=1;
	Init();
	scanf("%d",&c);
	getchar();
	while(c--)
	{
		gets(s);
		printf("Case #%d: ",ca++);
		for(i=0;s[i];i++)
		{
			if(s[i]==' ')
				putchar(' ');
			else
				putchar(g[s[i]]);
		}
		putchar('\n');
	}
	return 0;
}