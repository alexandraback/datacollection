#include<stdio.h>
double a,b,c;
double p,q;
double s[2000000];
double d[2000000];

int main()
{
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small-attempt0.out","wt",stdout);
	int t;
	scanf("%d",&t);
	int i, j, k;
	int tt=0;
	while(t--)
	{
		tt++;
		printf("Case #%d: ",tt);
		s[0] = 0;
		scanf("%lf %lf %lf",&a,&b,&c);
		d[0] = c / 2;
		int cnt=0;
		for(i=1;i<200000;i++)
		{
			p = a/(2+b*(i-1)) + s[i-1];
			q = c/(2+b*i);
			s[i] = p;
			d[i] = p+q;
			if(d[i] > d[i-1])
				cnt++;
			else cnt=0;
			if(cnt > 10)
				break;
		}
		double mm=d[0];
		for(j=1;j<i;j++)
			if(mm>d[j])
				mm=d[j];
		printf("%lf\n",mm);
	}
}