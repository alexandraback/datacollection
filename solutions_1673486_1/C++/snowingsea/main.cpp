#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

double p[100000];
double pp[1000000];
double s[100000];
int main(){
	freopen("D:\\Temp\\A-large.in","r",stdin);
	freopen("out.txt","w",stdout);

	int t,a,b;
	int i,cas = 1;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&a,&b);
		for(i = 0;i < a;i++)
			scanf("%lf",&p[i]);

		pp[0] = 1 - p[0];
		pp[1] = p[0];
		for (i = 1; i < a;i++)
		{
			pp[i+1] = pp[i] * p[i];
			pp[i] *= (1-p[i]);
		}

		s[a] = pp[a];
		for (i = a-1;i >= 0;i--)
			s[i] = s[i+1] + pp[i];
		double minE = 1 + b + 1;
		for (i = 0;i <= a;i++)
		{
			double e = s[a-i] * (i+b-a+i+1) + (1-s[a-i])*(i+b-a+i+1+b+1);
			minE = min(minE,e);
		}
		printf("Case #%d: %.6f\n",cas++,minE);

	}


	return 0;
}