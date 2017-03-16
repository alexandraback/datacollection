#include <stdio.h>


const int maxn = 200000;

double a[maxn+1],f[maxn+1];
double result;
int A,B;

FILE *fin=fopen("A.in","r"),
	*fout=fopen("A.out","w");

void init()
{
	int i;
	fscanf(fin,"%d%d",&A,&B);
	f[0]=1;
	for (i=1; i<=A; ++i)
	{
		fscanf(fin,"%lf",&a[i]);
		f[i]=f[i-1]*a[i];
	}
	B-=A; 
}

void update(double num)
{
	if (num<result)
		result=num;
}

void work()
{
	int i,t;
	result=(A+B)*10;
	update(f[A]*(B+1)+(1-f[A])*(B+1+A+B+1));
	for (i=1; i<=A; ++i)
		update(f[A-i]*(i+i+B+1)+(1-f[A-i])*(i+i+B+1+A+B+1));
	update(1+A+B+1);
}

void output()
{
	fprintf(fout,"%.6lf\n",result);
}

int main()
{
	int t,i;
	fscanf(fin,"%d",&t);
	for (i=1; i<=t; ++i)
	{
		fprintf(fout,"Case #%d: ",i);
		init();
		work();
		output();
	}
	fclose(fin);
	fclose(fout);
	return 0;
}