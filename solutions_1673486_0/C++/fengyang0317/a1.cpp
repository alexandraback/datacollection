#include <iostream>
using namespace std;
double s[1000000];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("aout.txt","w",stdout);
	int t,cas,i,j,a,b;
	double rate,last;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		last=1;
		scanf("%d%d",&a,&b);
		for(i=0;i<a;i++)
		{
			scanf("%lf",&rate);
			s[i]=last*(1-rate);
			last=last*rate;
		}
		s[i]=last;
		/*for(i=0;i<=a;i++)
			printf("%lf ",s[i]);
		puts("");*/
		double ans=b+2;
		for(i=0;i<=a;i++)
		{
			double tans=0;
			for(j=a;j>=0;j--)
			{
				if(a-j<=i)
				{
					tans+=s[j]*(b-a+1+i+i);
					//printf("-------%lf\n",s[j]*(b-a+1+i+i));
				}
				else
				{
					tans+=s[j]*(b-a+1+i+i+b+1);
					//printf("-------%lf\n",s[j]*(b-a+1+i+i));
				}
			}
			if(tans<ans)ans=tans;
		}
		printf("Case #%d: %.6lf\n",cas,ans);
	}
	return 0;
}