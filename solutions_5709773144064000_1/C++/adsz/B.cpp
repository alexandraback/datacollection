#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	for(int cn = 1; cn<=t; cn++)
	{
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);
		
		double t = 0.0;
		double cps = 2.0;
		
		for(;;)
		{
			//cookies = 0
			double next_t = t+c/cps;
			double reachx_t = t+x/cps;
			
			if(reachx_t < next_t)
			{
				printf("Case #%d: %.7f\n", cn, reachx_t);
				break;
			}
			
			t = next_t;
			//cookies  = c;
			
			double buy_time = t + x/(cps+f);
			double nobuy_time  = t + (x-c)/(cps);
			
			
			if(nobuy_time < buy_time)
			{
				printf("Case #%d: %.7f\n", cn, nobuy_time);
				break;
			}
			else
			{
				cps += f;
			}
		}
	}
}
