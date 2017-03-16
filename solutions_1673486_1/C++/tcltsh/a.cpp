#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int t;
double k[105000];

int main()
{
	FILE *in,*out;
	in=fopen("a.in","r");
	out=fopen("a.out","w");
	fscanf(in,"%d",&t);
	for(int tt=1;tt <= t;tt++)
	{
		int a,b;
		fscanf(in,"%d%d",&a,&b);
		for(int i=0;i<a;i++)
			fscanf(in,"%lf",&k[i]);
		double exp=b+2;

		double ar=1;
		for(int i=0;i<a;i++)
			ar *= k[i];
		exp=min(exp,ar*(b-a+1)+(1-ar)*(b-a+1+b+1));

		ar=1;
		for(int i=0;i < a;i++)
		{
			ar *= k[i];
			double nexp;
			nexp=ar*(a-i-1+a-i-1+b-a+1)+(1-ar)*(a-i-1+a-i-1+b-a+1+b+1);
			exp=min(exp,nexp);
		}
		fprintf(out,"Case #%d: %.6lf\n",tt,exp);
	}
	return 0;
}

