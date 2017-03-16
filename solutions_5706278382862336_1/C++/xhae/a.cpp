#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++)
	{
		long long a, b;
		scanf("%lld/%lld", &a, &b);
		long long gv = __gcd(a, b);
		a /= gv, b /= gv;

		int ans = -1, step = 0;
		while(true)
		{
			step++;
			if(step == 41) { ans = -1; break; }
			if(b % 2 == 1) { ans = -1; break; }

			b /= 2;
			if(a == b)
			{
				if(ans == -1) ans = step;
				break;
			}

			if(a > b)
			{
				if(ans == -1) ans = step;
				a -= b;
			}
		}

		if(step == 41) ans = -1;

		printf("Case #%d: ", kase);
		if(ans == -1) printf("impossible\n");
		else printf("%d\n", ans);
	}

	return 0;
}
