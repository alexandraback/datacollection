#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int ans = 0;
	for(int tc=1; tc <= T; tc++)
	{
		long long N;
		scanf("%lld", &N);

		set<long long> chk;
		long long n;
		int mask = 0;
		for(n = N; true; n += N)
		{
			if(chk.count(n))
				break;
			chk.insert(n);
			for(long long m=n; m; m/=10)
				mask |= 1 << (m % 10);
			if(mask == 1023)
				break;
		}

		printf("Case #%d: ", tc);
		if(mask == 1023)
			printf("%lld\n", n);
		else
			puts("INSOMNIA");
	}
	return 0;
}