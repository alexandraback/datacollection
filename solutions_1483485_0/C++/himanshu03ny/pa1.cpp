#include<cstdio>
int main()
{
	char c[256],ch,s[110];
	c[' ']=' ';
	c['a']='y';
	c['b']='h';
	c['c']='e';
	c['d']='s';
	c['e']='o';
	c['f']='c';
	c['g']='v';
	c['h']='x';
	c['i']='d';
	c['j']='u';
	c['k']='i';
	c['l']='g';
	c['m']='l';
	c['n']='b';
	c['o']='k';
	c['p']='r';
	c['q']='z';
	c['r']='t';
	c['s']='n';
	c['t']='w';
	c['u']='j';
	c['v']='p';
	c['w']='f';
	c['x']='m';
	c['y']='a';
	c['z']='q';
	int t;
	scanf("%d", &t);
	scanf("%c", &ch);
	int g=1,i;
	while(t--)
	{
		scanf("%[^\n]", s);
		scanf("%c", &ch);
		printf("Case #%d: ", g++);
		for(i=0;s[i];i++)
		{
			printf("%c", c[s[i]]);
		}
		printf("\n");
	}
	return 0;


}
