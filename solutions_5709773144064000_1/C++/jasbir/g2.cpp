#include<cstdio>
using namespace std;
int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{   int flag=0;
		printf("Case #%d: ",tc);
		double c,f,x;
		scanf("%lf",&c);scanf("%lf",&f);scanf("%lf",&x);
		double a,b;
		double ans=0.0;
		double pt=2+f;
		double p=2;
		a=x/p;b=x/pt + c/p;
		if(a<b) ans=x/p;
		while(a>=b)
		{ // printf("here   %lf    %lf    %lf\n",ans,a,b);
		flag=1;
			ans=ans+c/p;
			p=pt;
			pt=pt+f;
			
			a=x/p; b=x/pt + c/p;
			
			
		} 
		if(flag)
		ans=ans+a; //printf("here   %lf    %lf    %lf\n",ans,a,b);
		printf("%.7lf\n",ans);
	}
}
