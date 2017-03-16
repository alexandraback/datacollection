#include <stdio.h>

int A[10];

void digit(int n)
{
	if(!n) return;
	digit(n/10);
	A[n%10]=1;
}

int check()
{
	int i;
	for(i=0;i<10;i++) if(!A[i]) return 0;
	return 1;
}

FILE* in=fopen("A-large.in","r");
FILE* out=fopen("out.txt","w");

int main()
{
	int i,j,t,n;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fscanf(in,"%d",&n);
		fprintf(out,"Case #%d: ",i);
		if(!n) fprintf(out,"INSOMNIA\n");
		else
		{
			for(j=0;j<10;j++) A[j]=0;
			for(j=n;;j+=n)
			{
				digit(j);
				if(check())
				{
					fprintf(out,"%d\n",j);
					break;
				}
			}
		}
	}
	
	return 0;
}
