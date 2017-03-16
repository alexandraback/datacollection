#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T,TT;
double C,F,X,ans,speed,t;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lf%lf%lf",&C,&F,&X);
		ans=X/2;
		t=C/2;speed=2+F;
		while (t<ans)
		{
			ans=min(ans,t+X/speed);
			t+=C/speed;
			speed+=F;
		}
		printf("Case #%d: %.10f\n",++TT,ans);
	}
	
	return 0;
}