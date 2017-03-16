#include <bits/stdc++.h>

using namespace std;

long long isPrime(long long n)
{
	for(long long i=2; i * i <= n; i++)
		if(n % i == 0)
			return i;
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		printf("Case #%d:\n", tc);

		int N, M;
		scanf("%d%d", &N, &M);
		
		char a[33];
		a[0] = a[N-1] = '1';
		a[N] = 0;
		for(int i=0; M; i++)
		{
			for(int j=1; j < N-1; j++)
				a[j] = (i >> (N-2 - j)) % 2 + '0';

			bool find = true;

			long long b[11];
			for(long long j=2; j <= 10; j++)
			{
				long long n = 0;
				for(int k=0; k < N; k++)
					n = n * j + a[k] - '0';

				b[j] = isPrime(n);
				if(b[j] == 0)
				{
					find = false;
					break;
				}
			}

			if(!find)
				continue;

			M--;

			printf("%s ", a);
			for(int j=2; j <= 10; j++)
				printf("%lld ", b[j]);
			puts("");
		}
	}
	return 0;
}
