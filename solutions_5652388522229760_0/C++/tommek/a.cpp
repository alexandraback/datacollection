#include <bits/stdc++.h>

using namespace std;

bool czy[10];

int main()
{
	int ttte; scanf("%d", &ttte); for (int ttt = 1; ttt <= ttte; ++ ttt)
	{
		fill(czy, czy+10, false);
		
		printf("Case #%d: ", ttt);
		
		long long n; scanf("%lld", &n);
		long long ans = -1;
		long long v = n;
		
		for (int i = 0; i < 1e6; ++ i)
		{
			long long tem = v;
			while (tem > 0)
			{
				czy[tem%10LL] = true;
				tem /= 10LL;
			}
			bool asl = true;
			for (int j = 0; j < 10; ++ j)
			{
				if (!czy[j])
				{
					asl = false;
				}
			}
			if (asl)
			{
				ans = v;
				break;
			}
			v += n;
		}
		
		if (ans == -1)
		{
			puts("INSOMNIA");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}
}
