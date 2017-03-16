#include <iostream>
#include <algorithm>
using namespace std;

int T,A,B;
double p[100010];

double work()
{
	double suc=1,min_hit=1e30,hit;

	suc=1;
	for(int i=1;i<=A;i++)
		suc*=p[i];
	hit=suc*(B-A+1)+(1-suc)*(2*B-A+2);
	min_hit=hit;

	hit=B+2;
	if(hit<min_hit)
		min_hit=hit;

	suc=1;
	p[0]=1;
	for(int i=0;i<=A-1;i++)
	{
		suc*=p[i];
		hit=suc*(A+B-2*i+1)+(1-suc)*(A+2*B-2*i+2);
		if(hit<min_hit)
			min_hit=hit;
	}
	return min_hit;
}
int main()
{
//freopen("in","r",stdin);
//freopen("out","w",stdout);
	scanf("%d",&T);
	for(int cnb=1;cnb<=T;cnb++)
	{
		scanf("%d%d",&A,&B);
		for(int i=1;i<=A;i++)
			scanf("%lf",p+i);
		printf("Case #%d: %lf\n",cnb,work());
	}
}