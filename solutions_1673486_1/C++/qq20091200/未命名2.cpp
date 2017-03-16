#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXM=100010;

int A,B;
double p[MAXM],pre[MAXM];

double version_three()
{
	double d=0;
	if(A==B)
	{
		d+=pre[A]*1;
		d+=(1-pre[A])*(B+2);
	}
	else d+=B+2;
	return d;
}

double version_one(int x)
{
	double d=0;
	d=pre[x]*(B-x+1+A-x);
	if(x==0) d+=(1.0-pre[x])*(B-x+A-x+1);
	else d+=(1.0-pre[x])*(2*B-x+2+A-x);
	return d;
}

double version_two()
{
	double d=0;
	int i,j;
	for(i=1;i<=A;i++)
	{
		if(i==1) d=version_one(A-i);
		else d=min(d,version_one(A-i));
	}
	return d;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		scanf("%d%d",&A,&B);
		int i,j;
		for(i=1;i<=A;i++)
		{
			scanf("%lf",&p[i]);
			pre[i]=p[i];
			if(i>1) pre[i]*=pre[i-1];
		}
		double res;
		res=version_three();
		res=min(res,version_one(A));
		res=min(res,version_two());
		printf("Case #%d: %.6lf\n",cas,res);
	}
	return 0;
}
