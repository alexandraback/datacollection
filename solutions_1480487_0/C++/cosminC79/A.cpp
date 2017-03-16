#include <stdio.h>
#define NMAX 205
#define eps 1e-8
int t,n,A[NMAX],x;
inline double max(double x,double y)
{
	return x>y ? x : y;
}
inline int ok(double val,int poz)
{
	int i;
	double need=0;
	for (i=1; i<=n; i++)
		if (i!=poz)
			need+=max((A[poz]+val*x-A[i])/x,0);
	if (need+val>1.0)
		return 0;
	return 1;
}
double cbin(int poz)
{
	double i,step=1;
	for (i=0; step>eps; step/=2)
		if (i+step<1.0 && ok(i+step,poz))
			i+=step;
	i+=eps;
	return i*100;
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&t);
	int i,cnt=0;
	while (t--)
	{
		x=0; cnt++;
		scanf("%d",&n);
		for (i=1; i<=n; i++)
			scanf("%d",&A[i]),x+=A[i];
		printf("Case #%d: ",cnt);
		for (i=1; i<=n; i++)
			printf("%lf ",cbin(i));
		printf("\n");
	}
	return 0;
}
