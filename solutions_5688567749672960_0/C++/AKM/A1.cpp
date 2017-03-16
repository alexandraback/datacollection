#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 10000000;
const int INF = 100000000;

int dp[MAXN];
queue<int> q;

int rev(int x)
{
	int ans = 0;
	while (x)
	{
		ans = ans * 10 + x % 10;
		x /= 10;
	}
	return ans;
}

int main()
{
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; tc++)
	{
		cout << "Case #" << tc << ": ";
		int n;
		cin >> n;
		for (int i = 0; i < MAXN; i++)
			dp[i] = INF;
		dp[1] = 1;
		q.push(1);
		while (!q.empty())
		{
			int v = q.front();
			if (v == n)
				break;
			q.pop();
			if (v + 1 < MAXN && dp[v + 1] > dp[v] + 1)
			{
				dp[v + 1] = dp[v] + 1;
				q.push(v + 1);
			}
			int u = rev(v);
			if (dp[u] > dp[v] + 1)
			{
				dp[u] = dp[v] + 1;
				q.push(u);
			}

		}
		cout << dp[n] << endl;
	}

}
