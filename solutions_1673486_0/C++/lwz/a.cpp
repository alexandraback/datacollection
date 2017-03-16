#include<cstdio>
using namespace std;
int main()
{
int T,N;
scanf("%d",&N);
for(T=1;T<=N;T++)
{
	int a,n,m,c1,c2;
	double mn,p,p2,t;
	scanf("%d%d",&n,&m);
	mn=(double)m+2.;
	p=1.;
	c1=n+m+1;
	c2=n+m+1+m+1;
	for(a=n;a>=0;a--)
	{
		t=p*c1+(1.-p)*c2;
		if( t<mn ) mn=t;
		if( a==0 ) break;
		scanf("%lf",&p2);
		p*=p2;
		c1-=2;
		c2-=2;
	}
	printf("Case #%d: %lf\n",T,mn);
}
	return 0;
}
