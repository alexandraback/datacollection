#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>

using namespace std;

#define maxn 1100000
char ch[maxn];
int mat[200],a[210];
int main()
{
	int t,i,ca,len;
	mat['a']='y';
	mat['b']='h';
	mat['c']='e';
	mat['d']='s';
	mat['e']='o';
	mat['f']='c';
	mat['g']='v';
	mat['h']='x';
	mat['i']='d';
	mat['j']='u';
	mat['k']='i';
	mat['l']='g';
	mat['m']='l';
	mat['n']='b';
	mat['o']='k';
	mat['p']='r';
	mat['q']='z';
	mat['r']='t';
	mat['s']='n';
	mat['t']='w';
	mat['u']='j';
	mat['v']='p';
	mat['w']='f';
	mat['x']='m';
	mat['y']='a';
	mat['z']='q';
	scanf("%d",&t);
	gets(ch);
	for(ca=1;ca<=t;ca++)
	{
		printf("Case #%d: ",ca);
		gets(ch);
		len=strlen(ch);
		for(i=0;i<len;i++)
		{
			if(ch[i]==' ')putchar(' ');
			else putchar(mat[ch[i]]);
		}
		printf("\n");
	}
}
