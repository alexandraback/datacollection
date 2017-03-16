#include <cstdio>

#define TESTCASE "C-small-attempt0"

/*
4
1 9
10 40
100 500
1111 2222

Case #1: 0
Case #2: 3
Case #3: 156
Case #4: 287
*/

int numdigits(int n)
{
	int digits=0;
	for(;n>0;n/=10) ++digits;
	return digits;
}

int rotate(int n,int digits,int* topdigit)
{
	int factor=1;
	for(int i=1;i<digits;++i) factor*=10;

	*topdigit=n%10;
	return n/10+n%10*factor;
}

int main()
{
	FILE* fin=fopen(TESTCASE ".in","r");
	FILE* fout=fopen(TESTCASE ".out","w");
	int testcases;
	fscanf(fin,"%d",&testcases);
	for(int t=0;t<testcases;++t)
	{
		int a,b,count=0;
		fscanf(fin,"%d %d",&a,&b);
		for(int n=a;n<=b;++n)
		{
			int nd=numdigits(n);
			int td,i=n;
			
			while((i=rotate(i,nd,&td))!=n)
			{
				if(td==0) continue;
				if(a<=i && i<n)
				{
					++count;
					//fprintf(fout,"[%d] %d %d\n",count,n,i);
				}
			}
		}
		fprintf(fout,"Case #%d: %d\n",t+1,count);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}