#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define real int

double C,F,X,E;

double getNFarmDays(int n)
{
	double days=0;
	for(int i=0;i<n;i++)
	{
		days+=C/(E+i*F);
	}
	days+=X/(E+n*F);
	return days;
}

double getNFarmDays2(int n)
{
	float days=0;
	//float 
	for(int i=0;i<n;i++)
	{
		days+=C/(E+i*F);
	}
	days+=X/(E+n*F);
	return days;
}


double getDays()
{	
	double n=(X*F)/C-E-F;
	n/=F;
	int in=n;
	if(n<=0) in=0;
	return std::min(getNFarmDays(in),getNFarmDays(in+1));
}
void main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);

	int times;
	scanf("%d",&times);
	E=2;
	for(int time=1;time<=times;time++)
	{
		scanf("%lf %lf %lf",&C,&F,&X);
		printf("Case #%d: %.7lf\n",time,getDays());
	}
}