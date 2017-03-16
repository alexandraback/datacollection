#include <stdio.h>

FILE* in=fopen("D-large.in","r");
FILE* out=fopen("out.txt","w");

int digit[100];

long long f(int k,int c)
{
	long long p=1,ret=0;
	while(c--)
	{
		ret+=p*digit[c];
		p*=k;
	}
	return ret+1;
}

int main()
{
	int i,t;
	int j,p,v,k,c,s;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fscanf(in,"%d %d %d",&k,&c,&s);
		fprintf(out,"Case #%d: ",i);
		if(s*c<k) fprintf(out,"IMPOSSIBLE\n");
		else
		{
			v=0;
			for(j=0;j<=(k-1)/c;j++)
			{
				for(p=0;p<c;p++)
				{
					digit[p]=v;
					v=(v+1)%k;
				}
				fprintf(out,"%lld ",f(k,c)); 
			}
			fprintf(out,"\n");
		}
	}
	
	return 0;
}
