#include<cstdio>

int main()
{
	freopen("B.in", "r", stdin);
	
	int T;
	double ans, C, F, X; 
	scanf("%d", &T);
	for(int o=0; o<T; o++){
		ans = 0;
		scanf("%lf%lf%lf", &C, &F, &X);

		double now = 2;
		if (X > C){
			for(; X/(now+F) < (X-C)/now; now += F)
				ans += C/(now);
//				printf("%lf %lf\n", now, C/now);
			
//			printf("%lf\n", );
			ans += X / now;
		} else ans = X / 2;
	
		printf("Case #%d: %.7lf\n", o+1, ans);
	}
	return 0;
}
