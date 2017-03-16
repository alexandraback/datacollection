#include <bits/stdc++.h>

using namespace std;

int a[10];
int b[40];
int C, D, V;

void dfs(int k, int sum)
{
	if (k == D)
	{
		if (sum <= V)
		{
			b[sum] = 1;
		}
		return;
	}
	dfs(k + 1, sum + a[k]);
	dfs(k + 1, sum);
}

int main()
{
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int cas = 0;
	while (T--)
	{
		printf("Case #%d: ", ++cas);
		cin >> C >> D >> V;
		memset(b, 0, sizeof(b));
		for (int i = 0; i < D; ++i)
		{
			cin >> a[i];
		}
		dfs(0, 0);
		int sum = 0;
		for (int i = 0; i < 5; ++i)
		{
			int k = 1 << i;
			if (k > V)
			{
				break;
			}
			if (b[k] == 0)
			{
				sum++;
				for (int j = V; j; --j)
				{
					if (j + k <= V && b[j])
					{
						b[j + k] = 1;
					}
				}
			}
		}
		cout << sum << endl;
	}

	 fclose(stdin);
	 fclose(stdout);
	return 0;
}