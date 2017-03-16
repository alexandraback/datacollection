#include<cstdio>

int main()
{
	int T; scanf("%d", &T);
	for(int ii = 0; ii < T; ii++)
	{
		double time = 0;
		double C, F, X; scanf("%lf%lf%lf",&C,&F,&X);
		int farms = 0;
		while(X/(2+farms*F) > C/(2+farms*F)+X/(2+(farms+1)*F))
		{
			time += C/(2+farms*F);
			farms++;
		}
		printf("Case #%d: %.7lf\n",ii+1,time+X/(2+farms*F));
	}
}
