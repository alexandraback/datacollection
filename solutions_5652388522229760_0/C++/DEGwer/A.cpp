#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	freopen("a-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int data;
	scanf("%d", &data);
	for (int p = 1; p <= data; p++)
	{
		ll z;
		scanf("%lld", &z);
		if (z == 0)
		{
			printf("Case #%d: INSOMNIA\n", p);
			continue;
		}
		ll now = z;
		int dat[10];
		int cnt = 0;
		fill(dat, dat + 10, 0);
		for (;;)
		{
			ll t = now;
			for (;;)
			{
				if (t == 0)break;
				if (dat[t % 10] == 0)cnt++;
				dat[t % 10]++;
				t /= 10;
			}
			if (cnt == 10)
			{
				printf("Case #%d: %lld\n", p, now);
				break;
			}
			now += z;
		}
	}
}