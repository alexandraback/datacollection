#include <iostream>
#include <cstdio>

using namespace std;

double prob[100003];
double cor[100003];

int main()
{
	int t;
	scanf("%d", &t);
	for(int it=1;it<=t;it++)
	{
		double ans;
		int a, b;
		scanf("%d %d",&a, &b);
		ans = b+2;
		for(int i=1;i<=a;i++)
		{
			scanf("%lf",&prob[i]);
		}
		cor[0] = 1;
		prob[0] = 0;
		for(int i=1;i<=a; i++){
			cor[i] = cor[i-1]*prob[i];
		}

		for(int i=0; i<=a; i++){
			double tans = b-a+1+2*i;
			
			tans += (b+1)*(1-cor[a-i]);	
			//printf("cr:%lf %.5lf\n",cor[a-i],tans);
			ans = min(ans, tans);
		}
		printf("Case #%d: %.6lf\n",it, ans);
	}
	return 0;
}
