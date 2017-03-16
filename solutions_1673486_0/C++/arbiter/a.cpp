#include<stdio.h>
double c[100000];
double min(double x,double y)
{
	if(x<y)return x;
	return y;
}
main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A2.txt","w",stdout);
	int abc,i,j,T;
	double ans,a,b;
	scanf("%d",&T);
	for(abc=0;abc<T;abc++)
	{
		scanf("%lf %lf",&a,&b);
		for(i=0;i<a;i++)
			scanf("%lf",&c[i]);
		//printf("%lf",c[0]);
		double tmp=1,j;
		ans=min(a+b+1,b+2);
		for(i=0,j=0;i<a;i++,j++)
		{
			double t=0;
			tmp*=c[i];
			t=tmp*(a-j-1+b-j)+(1-tmp)*(a-j-1+b-j+b+1);
			ans=min(ans,t);
		}
		printf("Case #%d: %.6lf\n",abc+1,ans);
	}
}
