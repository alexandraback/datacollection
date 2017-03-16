#include <stdio.h>

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tests,tcount;
	double c,f,x,time1,time2,s=2;
	scanf("%d",&tests);
	for(tcount=0;tcount<tests;tcount++)
	{
		s=2;
		scanf("%lf",&c);
		scanf("%lf",&f);
		scanf("%lf",&x);
		time1=x/s;
		time2=c/s+x/(f+s);
		while(time2<time1)
		{
			time1=time2;
			s=s+f;
			time2=time1-x/s+c/s+x/(f+s);
		}
		printf("Case #%d: %.7lf\n",tcount+1,time1);
	}
    return 0;
}
