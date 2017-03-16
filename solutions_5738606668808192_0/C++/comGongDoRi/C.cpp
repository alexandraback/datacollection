#include <stdio.h>

FILE* in=fopen("C-small-attempt0.in","r");
FILE* out=fopen("out.txt","w");

char P[101];

int f()
{
	char prev=P[0];
	int i,ret=0;
	for(i=0;P[i];i++)
	{
		if(P[i]!=prev) ret++;
		prev=P[i];
	}
	return ret+1-(prev=='+');
}

int check(unsigned int n)
{
	return n?n%2-check(n/2):0;
}

void print(unsigned int n)
{
	if(n)
	{
		print(n/2);
		fprintf(out,"%d",n%2);
	}
}

int main()
{
	int i,t;
	int n,j,k;
	unsigned int bin;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fscanf(in,"%d %d",&n,&j);
		fprintf(out,"Case #%d: \n",i);
		bin=(1<<(n-1))+1;
		while(j)
		{
			if(check(bin)==0)
			{
				print(bin);
				fprintf(out," ");
				for(k=2;k<=10;k++) fprintf(out,"%d ",k+1);
				fprintf(out,"\n");
				j--;
			}
			bin+=2;
		}
	}
	
	return 0;
}
