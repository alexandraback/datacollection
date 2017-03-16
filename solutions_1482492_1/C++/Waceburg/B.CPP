#include<stdio.h>
#include<math.h>
typedef struct
{
	double t,dis;
}Other;
Other car[2005];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int t,c,n,i,m;
	double a,d,osp,msp,tt,td,t1,t2,start,ts;
	scanf("%d",&t);
	for(c=1;c<=t;c++)
	{
		printf("Case #%d:\n",c);
		scanf("%lf%d%d",&d,&n,&m);
		for(i=0;i<n;i++) scanf("%lf%lf",&car[i].t,&car[i].dis);
		while(m--)
		{
			scanf("%lf",&a);
			msp=tt=td=0;
			start=car[0].dis;
			for(i=1;i<n;i++)
			{
				osp=(car[i].dis-car[i-1].dis)/(car[i].t-car[i-1].t);
				t1=(osp-msp+sqrt((msp-osp)*(msp-osp)+2*a*start))/a;
				ts=msp*t1+0.5*a*t1*t1;
				if(t1<=car[i].t-car[i-1].t)
				{
					if(car[i].dis>=d)
					{
						if(td+ts>=d) t2=(sqrt(msp*msp-2*a*(td-d))-msp)/a;
						else t2=t1+(d-td-ts)/osp;
						tt+=t2;
						td=d;
						break;
					}
					msp=osp;
					start=0;
					td=car[i].dis;
				}
				else
				{
					ts=msp*(car[i].t-car[i-1].t)+0.5*a*(car[i].t-car[i-1].t)*(car[i].t-car[i-1].t);
					if(td+ts>=d)
					{
						tt+=(sqrt(msp*msp-2*a*(td-d))-msp)/a;
						td=d;
						break;
					}
					start+=osp*(car[i].t-car[i-1].t)-ts;
					td+=ts;
					msp+=a*(car[i].t-car[i-1].t);
				}
				tt+=car[i].t-car[i-1].t;
			}
			if(td<d) tt+=(sqrt(msp*msp-2*a*(td-d))-msp)/a;
			printf("%.7f\n",tt);
		}
	}
	return 0;
}