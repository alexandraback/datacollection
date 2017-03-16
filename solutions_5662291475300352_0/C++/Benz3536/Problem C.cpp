#include<bits/stdc++.h>
using namespace std;
main()
{
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("out-C-small-1.txt","w",stdout);
	int a,b,c,p1,q1,r1,p2,q2,r2;
	double time1,time2,round;
	scanf("%d",&a);
	for(b=0;b<a;b++)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d %d %d",&p1,&q1,&r1);
			if(q1==1)printf("Case #%d: 0\n",b+1);
			else 
			{
				round=(double(360-p1)/360.0*double(r1+1))/double(r1);
				round-=1.0;
				if(round>=double(360-p1)/360.0)printf("Case #%d: 1\n",b+1);
				else printf("Case #%d: 0\n",b+1);
			}
		}
		else
		{
			scanf("%d %d %d",&p1,&q1,&r1);
			scanf("%d %d %d",&p2,&q2,&r2);
			time1=(double(360-p1)/360.0*double(r1));
			time2=(double(360-p2)/360.0*double(r2));
			if(time1>time2)
			{
				swap(p1,p2);
				swap(q1,q2);
				swap(r1,r2);
				swap(time1,time2);
			}
			if(time1+r1<=time2)printf("Case #%d: 1\n",b+1);
			else printf("Case #%d: 0\n",b+1);
		}
	}
}
