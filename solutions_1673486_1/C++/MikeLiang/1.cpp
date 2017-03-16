#include <iostream>
#include <cstdio>
#include <cmath>
#define M 100003
using namespace std;


double num[M];
double cu[M];
int ex[M];

int main()
{


	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);


	int cas,n,m;
	scanf("%d",&cas);
	for(int T=1;T<=cas;T++)
	{
		int i,j,k;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lf",&num[i]);

		double temp = 1;
		for(i=0;i<n;i++)
		{
			temp *= num[i];
			cu[i] = 1-temp;
		}


		double rank = m+1+1;

		for(i=0;i<n;i++)
		{
			double tt = 1;
			tt = (i*2 + m-n+1)*(1-cu[n-i-1]) + (i*2 + m-n+1 + m+1)*cu[n-i-1];
			rank = min(rank,tt);
		}

		
		printf("Case #%d: %.6lf\n",T,rank);

	}

	return 0;
}
