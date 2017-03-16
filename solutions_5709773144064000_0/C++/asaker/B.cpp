#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int TC;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		double C,F,X,R=2.0,T=0;
		bool inc=1;
		scanf("%lf %lf %lf",&C,&F,&X);
		printf("Case #%d: ",tc);
		if(C>=X)
		{
			//printf("%.7f\n",X/R);
			T=X/R;
			inc=0;
		}
		while(inc)
		{
			if(((C/R) + (X/(R+F)) )< X/R)
			{
				T+=C/R;
				R+=F;
			}
			else
			{
				T+=X/R;
				break;
			}
		}
		printf("%.7f\n",T);
	}
}
