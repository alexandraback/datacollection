#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
typedef vector<int> VI;
int f(int n, bool surprising)
{
	bool flag = false;
	for (int i=10; i>=0; i--)
		for (int j=i; j>=0 && i-j<=2; j--)
			for (int k=j; k>=0 && i-k<=2; k--)
				if (i + j + k == n)
				{
					flag = true;
					if (i - k == 2)
					{
						if (surprising)
							return i;
					}
					else
					{
						if (!surprising)
							return i;
					}
				}
	assert(flag);
	return -1;
}
int main()
{
	int t;
	cin >> t;
	for (int tc=0; tc<t; tc++)
	{
		int n, s, p;
		cin >> n >> s >> p;
		VI dp(n + 1, -123456789);
		dp[0] = 0;
		for (int i=0; i<n; i++)
		{
			VI next(n + 1, -123456789);
			int x;
			cin >> x;
			for (int j=0; j<=i; j++)
			{
				if (f(x, true) >= p)
				{
					next[j + 1] = max(next[j + 1], dp[j] + 1);
				}
				if (f(x, true) >= 0)
				{
					next[j + 1] = max(next[j + 1], dp[j]);
				}
				if (f(x, false) >= p)
				{
					next[j] = max(next[j], dp[j] + 1);
				}
				if (f(x, false) >= 0)
				{
					next[j] = max(next[j], dp[j]);
				}
			}
			swap(dp, next);
		}
		assert(dp[s] >= 0);
		cout << "Case #" << tc + 1 << ": " << dp[s] << endl;
	}
	return 0;
}
