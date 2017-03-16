#include<cstdio>
#include<cstring>
char s[333],a[333];
int T,len;

int main()
{
//ejp mysljylc kd kxveddknmc re jsicpdrysi
//our language is impossible to understand

//rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
//there are twenty six factorial possibilities

//de kr kd eoya kw aej tysr re ujdr lkgc jv
//so it is okay if you want to just give up

    a['a']='y'; a['b']='h'; a['c']='e'; a['d']='s'; a['e']='o'; a['f']='c'; a['g']='v';
	a['h']='x'; a['i']='d'; a['j']='u'; a['k']='i'; a['l']='g'; a['m']='l'; a['n']='b';
	a['o']='k'; a['p']='r'; a['q']='z'; a['r']='t'; a['s']='n'; a['t']='w';
	a['u']='j'; a['v']='p'; a['w']='f'; a['x']='m'; a['y']='a'; a['z']='q';
	a[' ']=' ';
	
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d",&T);
	gets(s);
	for (int i=1; i<=T; i++)
	{
		gets(s);
		len=strlen(s);
		printf("Case #%d: ",i);
		for (int j=0; j<len; j++)
		    printf("%c",a[s[j]]);
		printf("\n");
    }
    return 0;
}
