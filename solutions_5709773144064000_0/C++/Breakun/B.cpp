#include <cstdio>
using namespace std;

double c, f, x;

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%lf %lf %lf", &c, &f, &x);
		printf("Case #%d: ", t);
		double rate = 2.0, ans = 0.0;
		while(x / rate > c / rate + x / (rate + f))
			ans += c / rate, rate += f;
		ans += x / rate;
		printf("%.7f\n", ans);
	}
	return 0;
}
