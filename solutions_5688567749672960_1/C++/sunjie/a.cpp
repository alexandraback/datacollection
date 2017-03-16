#include <bits/stdc++.h>

using namespace std;

int ten[9];
int dp[20];

void pre()
{
	ten[0] = 1;
	for (int i = 1; i < 9; ++i)
	{
		ten[i] = ten[i - 1] * 10;
	}
	dp[0] = 0;
	for (int i = 1; i <= 14; ++i)
	{
		dp[i] = ten[i / 2] - 1 + ten[(i + 1) / 2] + dp[i - 1];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	pre();
	int T;
	scanf("%d", &T);
	int cas = 0;
	while (T--)
	{
		printf("Case #%d: ", ++cas);
		int b[20];
		int size = 1;
		long long N;
		cin >> N;
		int sum = 0;
		if (N % 10 == 0)
		{
			N--;
			sum++;
		}
		while (N)
		{
			b[size++] = N % 10;
			N /= 10;
		}
		sum += dp[size - 2];
		int k = 0;
		for (int i = size / 2; i; --i)
		{
			k *= 10;
			k += b[i];
		}
		sum += k;
		k = 0;
		for (int i = size / 2 + 1; i < size; ++i)
		{
			k *= 10;
			k += b[i];
		}
		if (k > 1)
		{
			sum += k;
		}
		printf("%d\n", sum);
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}