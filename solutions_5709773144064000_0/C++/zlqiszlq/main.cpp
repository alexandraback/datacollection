#include <iostream>
#include <cstdio>
using namespace std;
#define MAXX 100000

double Time[MAXX + 1];
int T;
double C,F,X,S;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,j,k;
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		scanf("%lf%lf%lf",&C,&F,&X);
		S = F*X / C;
		int n = (int)((S-2) / F);
		double ans = 0.0;
		double num = 2.;
		for (i=0;i<n;i++,num += F)
		{
			ans += C / num;
		}
		ans += X / num;
		printf("Case #%d: %.8f\n",cases,ans);
	}
	return 0;
}
