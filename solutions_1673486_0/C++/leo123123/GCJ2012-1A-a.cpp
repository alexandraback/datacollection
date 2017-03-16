#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
double p[100005];
int main()
{
	freopen("G://GCJ/A-small.in","r",stdin);
	freopen("G://GCJ/1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		int A,B;
		memset(p,0,sizeof(p));
		scanf("%d%d",&A,&B);
		for (int j=0;j<A;j++)
		{
			scanf("%lf",&p[j]);
		}
		double p_now=1;
		double res=100000000;
		for (int j=0;j<A;j++)
		{
			p_now=p_now*p[j];
			double res_comp=(A+B-2*j-1)*p_now+(1.0-p_now)*(2*B+A-2*j);
			res=min(res,res_comp);
		}
		res=min(res,double(B+2));
		printf("Case #%d: %.6f\n",i+1,res);
	}	
	return 0;
}