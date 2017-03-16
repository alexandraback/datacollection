#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define Eps 1e-7
using namespace std;
int T;
double c,f,x;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int i;
	scanf("%d",&T);
	for (int ii=1;ii<=T;++ii)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		double ans=x/2.00,tmp=0,tot,rate=2;
		for (i=1;;++i)
		{
			tmp+=c/rate;
			rate+=f;
			tot=x/rate+tmp;
			if (tot>ans) break;
			if (fabs(tot-ans)<Eps) break;
			ans=tot;
		}
		printf("Case #%d: %.8lf\n",ii,ans);
	}
	//system("pause");
	return 0;
}
