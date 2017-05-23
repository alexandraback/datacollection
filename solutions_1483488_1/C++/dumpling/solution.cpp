#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long uint64;

int T, A, B;
bool vis[2000020];

int DigitNumber(int n)
{
	int k = 0;
	while(n)
	{
		n /= 10;
		++k;
	}
	return k;
}

int NextCircleNumber(int n, int K, int k)
{
	int mod = 1, mul = 1;
	for(int i = 0; i < k; ++i)
		mod *= 10;
	for(int i = 0; i < (K - k); ++i)
		mul *= 10;
	return n / mod + n % mod * mul;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &A, &B);
		uint64 ans = 0;
		int K = DigitNumber(A);
		for(int n = A; n <= B; ++n)
		{
			if(!vis[n])
			{
				vis[n] = true;
				int k = 1, m, c = 1;
				while(k <= K && (m = NextCircleNumber(n, K, k)) != n)
				{
					if(m >= A && m <= B && !vis[m])
					{
						vis[m] = true;
						++c;
					}
					++k;
				}
				ans += c * (c - 1) / 2;
			}
		}
		printf("Case #%d: %llu\n", t, ans);
	}
	return 0;
}