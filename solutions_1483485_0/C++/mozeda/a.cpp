#include <cstdio>
#include <cstring>

char a['z'];
int n,i,j;
char st[200];
int main()
{
	a['a']='y';
	a['b']='h';
	a['c']='e';
	a['d']='s';
	a['e']='o';
	a['f']='c';
	a['g']='v';
	a['h']='x';
	a['i']='d';
	a['j']='u';
	a['k']='i';
	a['l']='g';
	a['m']='l';
	a['n']='b';
	a['o']='k';
	a['p']='r';
	a['q']='z';
	a['r']='t';
	a['s']='n';
	a['t']='w';
	a['u']='j';
	a['v']='p';
	a['w']='f';
	a['x']='m';
	a['y']='a';
	a['z']='q';
	scanf("%d\n", &n);
	for (int i=1;i<=n;++i)
	{
		gets(st);
		printf("Case #%d: ", i);
		for (int j=0;j<strlen(st);++j)
			if (st[j]>='a' && st[j]<='z')
				putchar(a[st[j]]);
			else
				putchar(st[j]);
		printf("\n");
	}
} 
