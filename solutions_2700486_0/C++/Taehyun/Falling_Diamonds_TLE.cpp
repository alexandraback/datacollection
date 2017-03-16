#include<stdio.h>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
int T;
long long N;
long long X,Y;
long long All,Ans;
int Left,Right;
void dfs(int x,int Lim,int k)
{
	if(x==N)
	{
		All++;
		if(Right>=k) Ans++;
		return;
	}
	if(Left<Lim)
	{
		Left++;
		dfs(x+1,Lim,k);
		Left--;
	}
	if(Right<Lim)
	{
		Right++;
		dfs(x+1,Lim,k);
		Right--;
	}
}
int main()
{
	fscanf(in,"%d",&T);
	int t,i;
	long long x,y;
	for(t=1;t<=T;t++)
	{
		fscanf(in,"%lld %lld %lld",&N,&X,&Y);
		fprintf(out,"Case #%d: ",t);
		if(X<0) X=-X;
		x=(X+Y)/2;
		if(N<=(x*(2*x-1)+Y))
		{
			fprintf(out,"0.0\n");
			continue;
		}
		if(N>=((x+1)*(2*x+1)))
		{
			fprintf(out,"1.0\n");
			continue;
		}
		N-=(x*(2*x-1));
		if(X==0)
		{
			if(N<(4*x+1)) fprintf(out,"0.0\n");
			else fprintf(out,"1.0\n");
			continue;
		}
		Ans=0,All=0;
		Left=Right=0;
		dfs(0,2*x,Y+1);
		fprintf(out,"%.8lf\n",(double)Ans/(double)All);
	}
}