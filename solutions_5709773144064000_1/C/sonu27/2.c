#include <stdio.h>
int main()
{
	int c=1,t;
	long double C,F,X,R,t1,t2,ans,temp;
	scanf("%d",&t);
	while(c<=t)
	{
		scanf("%Lf %Lf %Lf",&C,&F,&X);
		R=2.0;
		ans=0.0;
		t1=C/R;
		t2=X/R;
		while(1)
		{
			temp=t2-t1;
			if((temp*(R+F)) > X)
			{
				R=R+F;
				ans+=t1;
				t1=C/R;
				t2=X/R;
			}
			else
			{
				ans+=t2;
				break;
			}
		}
		printf("Case #%d: %.7Lf\n",c,ans);
		c++;
	}
	return 0;
}