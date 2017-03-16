#include<stdio.h>
#include<algorithm>
main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int abc,T,i,j,n;
	double s[250],X;
	scanf("%d",&T);
	for(abc=1;abc<=T;abc++)
	{
		
		X=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lf",&s[i]);
			//t[i].num=i;
			//t[i].a=s[i];
			//s[i]*=100000;
			X+=s[i];
		}
		printf("Case #%d:",abc);
		double ub=200,lb=0;
		while(ub-lb>0.00000001)
		{
			double tmp=X;
			for(i=0;i<n;i++)
				if(s[i]<(ub+lb)/2)
					tmp-=((ub+lb)/2-s[i]);
			if(tmp<0)ub=(ub+lb)/2;
			else lb=(ub+lb)/2;
		}
		for(i=0;i<n;i++)
		{
			if(ub-s[i] < 0.0000001)
				printf(" %.6lf",0.0);
			else printf(" %.6lf",100*(ub-s[i])/X);
		}
		puts("");
		/*std::sort(t,t+n,cmp);	
		for(i=0;i<n;i++)
		{
			if(t[0].num!=i)
			{
				double tmp=s[i]-t[0].a;
				tmp=X-tmp;
				tmp/=2;
				tmp/=X;
				tmp*=100;
				printf(" %.6lf",tmp);
			}
			else
			{
				double tmp=s[i]-t[1].a;
				tmp=X-tmp;
				tmp/=2;
				tmp/=X;
				tmp*=100;
				printf(" %.6lf",tmp);
			}
		}
		puts("");*/
	}
}
