 //if you want,you can
#include<stdio.h>
#include<iostream>

using namespace std;

int t,n;
int zu[500];
const double small=0.000000001;
int sum;

int f(double m,int p)
{
	double gate=zu[p]+m*sum;
	double rem=1-m;

	for(int i=0;i<n;i++)
	{
		if(p!=i&&zu[i]<gate)
		{
			double sub=(gate+small-zu[i])/sum;
			if(rem<sub)
			{
				return 1;
			}
			rem-=sub;
		}
	}

	return 0;
}

double search(double a,double b,int p)
{
	double m=(a+b)/2;

	if(b-a<small)
	{
		return m;
	}

	if(f(m,p))
	{
		return search(a,m,p);
	}
	else
	{
		return search(m,b,p);
	}
}

int main()
{
	freopen("a.out","w",stdout);
	scanf("%d",&t);

	for(int tt=0;tt<t;tt++)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&zu[i]);
			sum+=zu[i];
		}

		printf("Case #%d:",(tt+1));
		for(int i=0;i<n;i++)
		{
			double ret=search(0,1,i);
			printf(" %.6lf",ret*100);
		}
		printf("\n");
	}
}
