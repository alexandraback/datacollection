#include<fstream>
#include<cmath>
#include<cstdio>
using namespace std;
int T,A,B,v[100100],r;
double p[100100],p1,p2[100100],p3,sol;

inline void Determinare()
{
	int i,poz=0;
	double pos=1.0;
	for(i=A;i>0;i--)
	{
		if(v[i]==1)
		{
			poz=i;
			pos*=(double)(1-p[i]);
		}
		else
			pos*=p[i];
	}
	if(poz!=0)
		p1+=pos*(double)(r+B+1);
	else
		p1+=pos*(double)r;
	for(i=1;i<=A;i++)
	{
		if(poz==0 || poz>A-i)
			p2[i]+=pos*(double)(r+2*i);
		else
			p2[i]+=pos*(double)(r+2*i+B+1);
	}
}

inline void Gen(int k)
{
	if(k==A+1)
		Determinare();
	else
	{
		v[k]=0;
		Gen(k+1);
		v[k]=1;
		Gen(k+1);
	}
}

int main()
{
	int t,i;
	ifstream fin("A.in");
	freopen("A.out","w",stdout);
	fin>>T;
	for(t=1;t<=T;t++)
	{
		fin>>A>>B;
		for(i=1;i<=A;i++)
		{
			fin>>p[i];
			p2[i]=0.0;
		}
		p1=p3=0.0;
		r=B-A+1;
		Gen(1);
		p3=B+2;
		sol=min(p1,p3);
		for(i=1;i<=A;i++)
			sol=min(sol,p2[i]);
		printf("Case #%d: %.6lf\n",t,sol);
	}
	return 0;
}
