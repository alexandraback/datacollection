#include<stdio.h>
#include<math.h>
#include<algorithm>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
struct LIST
{
	double t,x;
	bool operator()(LIST a,LIST b)
	{
		if(a.x!=b.x) return a.x<b.x;
		if(a.t!=b.t) return a.t<b.t;
		return 0;
	}
}list[10001];
int N,A;
double D;
double Solve(double a,double b,double c)
{
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}
int main()
{
	int T,t;
	int i;
	double a,X;
	double Ans,V0;
	fscanf(in,"%d",&T);
	for(t=1;t<=T;t++)
	{
		fscanf(in,"%lf %d %d",&D,&N,&A);
		for(i=1;i<=N;i++)
		{
			fscanf(in,"%lf %lf",&list[i].t,&list[i].x);
		}
		for(i=1;i<=N;i++) if(list[i].x==D) break;
		if(i==N+1)
		{
			for(i=1;i<=N;i++)
			{
				if(list[i].x>D) break;
			}
			list[++N].x=D;
			list[N].t=(list[i].t-list[i-1].t)/(list[i].x-list[i-1].x)*(D-list[i-1].x)+list[i-1].t;
			std::sort(list+1,list+1+N,LIST());
		}
		else
		{
			list[i+1].x=list[i].x;
			list[i+1].t=list[i].t;
		}
		fprintf(out,"Case #%d:\n",t);
		double tt;
		while(A--)
		{
			fscanf(in,"%lf",&a);
			V0=X=0; Ans=0;
			if(list[1].x>=D)
			{
				fprintf(out,"%.7lf\n",Solve(a/2,0,-D));
				continue;
			}
			for(i=1;i<=N;i++)
			{
				tt=Solve(a/2,V0,-(list[i+1].x-X));
				if(list[i+1].t-list[i].t<=tt)
				{
					Ans+=tt;
					V0+=a*tt;
				}
				else
				{
					Ans+=list[i+1].t-list[i].t;
					V0=a*tt;
				}
				X=list[i+1].x;
				if(list[i+1].x>=D) break;
			}
			fprintf(out,"%.8lf\n",Ans);
		}
		for(i=1;i<=N;i++) list[i].x=list[i].t=0;
	}
}