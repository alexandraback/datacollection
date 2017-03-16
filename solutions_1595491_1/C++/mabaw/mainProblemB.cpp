#include <stdio.h>

FILE *fin;
FILE *fout;

int t,n,s,p;
int x;
int countP,countCS;
int sum;
int main(int argc, char* argv[])
{



		fin = fopen("B-large.in","r");
		fout = fopen("B-large.out","w");
	
	fscanf(fin,"%d",&t);
	for(int i=0;i<t;i++)
	{
		countP=0;
		countCS=0;

		fscanf(fin,"%d %d %d",&n,&s,&p);
		for(int j=0;j<n;j++)
		{
			fscanf(fin,"%d",&x);
			int pp = p*3;
			if(x >= pp-2) countP++;
			else if(x >= pp-4 && x!=0) countCS++;
		}

		if(s > countCS) sum = countP+countCS;
		else sum = countP+s;
		fprintf(fout,"Case #%d: %d\n",i+1,sum);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}