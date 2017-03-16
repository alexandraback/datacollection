#include<cstdio>
using namespace std;
double const eps=1e-8;
void solve()
{
	double C,F,X,s=0.0,CS=2;
	scanf("%lf%lf%lf",&C,&F,&X);
	while(X/CS+eps>C/CS+X/(CS+F))
	{
		s+=C/CS;
		CS+=F;
	}
	s+=X/CS;
	printf("%.7lf\n",s);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}
