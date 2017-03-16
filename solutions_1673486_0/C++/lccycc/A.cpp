#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
double p[maxn];
int A,B;
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int runs = 1; runs <= T; runs++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		p[0]=1;
		for (int i = 1; i <= A; i++)
		{
			scanf("%lf",p+i);
			p[i]*=p[i-1];
		}
		double exp1 = 999999999;
		for (int k = 1; k <= A+1; k++)
		{
			double exp = A+B-2*(k-1)+1 + (B+1)*(1-p[k-1]);
			if (exp < exp1)
				exp1 = exp;
		}
		if (1+B+1 < exp1)
			exp1 = 1+B+1;

		printf("Case #%d: ",runs);
		printf("%.6f\n",exp1);
	}
	return 0;
}

