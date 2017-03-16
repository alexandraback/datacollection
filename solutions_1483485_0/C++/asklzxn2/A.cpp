#include<cstdio>
#include<cstring>
int T,i,j,l;
char c[128],s[105];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
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
	c[' ']=' ';
	scanf("%d",&T);
	gets(s);
	for(j=1;j<=T;++j)
	{
		gets(s);
		l=strlen(s);
		for(i=0;i<l;++i) s[i]=c[s[i]];
		printf("Case #%d: ",j);
		puts(s);
	}
	return 0;
}
