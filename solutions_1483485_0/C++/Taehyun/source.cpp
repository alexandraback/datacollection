#include<stdio.h>
#include<string.h>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
int Trans[300];
char Inp[101];
int main()
{
	Trans['a']='y';
	Trans['b']='h';
	Trans['c']='e';
	Trans['d']='s';
	Trans['e']='o';
	Trans['f']='c';
	Trans['g']='v';
	Trans['h']='x';
	Trans['i']='d';
	Trans['j']='u';
	Trans['k']='i';
	Trans['l']='g';
	Trans['m']='l';
	Trans['n']='b';
	Trans['o']='k';
	Trans['p']='r';
	Trans['q']='z';
	Trans['r']='t';
	Trans['s']='n';
	Trans['t']='w';
	Trans['u']='j';
	Trans['v']='p';
	Trans['w']='f';
	Trans['x']='m';
	Trans['y']='a';
	Trans['z']='q';
	int N;
	fscanf(in,"%d",&N);
	int i,j;
	int len;
	fgets(Inp,105,in);
	for(i=1;i<=N;i++)
	{
		fgets(Inp,105,in);
		len=strlen(Inp);
		fprintf(out,"Case #%d: ",i);
		for(j=0;j<len;j++)
		{
			if(Inp[j]==' ') fprintf(out," ");
			else if(Trans[Inp[j]]==0) continue;
			else fprintf(out,"%c",Trans[Inp[j]]);
		}
		fprintf(out,"\n");
	}
}