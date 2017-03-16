#include <stdio.h>
int t;
double c,f,x,ans,rate;
int main(int argc, char *argv[])
{
	scanf("%d",&t);
	for(int r=1;r<=t;r++)
	{
		scanf("%lf %lf %lf",&c,&f,&x);
		ans=0;
		rate=2.0;
		while(1) {
			if(x/rate<=c/rate+x/(rate+f)) {
				ans+=x/rate;
				break;
			}
			else {
				ans+=c/rate;
				rate+=f;
			}
		}
		printf("Case #%d: ",r);
		printf("%.7lf\n",ans);
	}
	
	return 0;
}
