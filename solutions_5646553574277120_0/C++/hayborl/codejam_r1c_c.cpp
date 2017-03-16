#include <iostream>

using namespace std;

typedef long long ll;

int solve(int C, int D, ll V, ll* d)
{
	int ans = 0;
	for (int i = 1; i <= V; i++)
	{
		bool flag = false;
		for (int j = 0; j < (1 << D); j++)
		{
			int tmp = j, sum = 0, ti = 0;
			while (tmp > 0)
			{
				if (tmp % 2 == 1)
				{
					sum += d[ti];
				}
				tmp /= 2;
				ti++;
			}
			if (sum == i)
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			ans++;
			d[D++] = i;
		}
	}

	return ans;
}

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);

	ll d[100];

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int C, D;
		ll V;
		cin >> C >> D >> V;

		for (int j = 0; j < D; j++)
		{
			cin >> d[j];
		}

		cout << "Case #" << i << ": " << solve(C, D, V, d) << endl;
	}

	return 0;
}