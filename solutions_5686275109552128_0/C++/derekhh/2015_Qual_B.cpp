//Problem B. Infinite House of Pancakes

#include <iostream>
using namespace std;

int num[1000];

int main()
{
	int t, kase = 0;
	cin >> t;
	while (t--)
	{
		int d, maxval = 0;
		cin >> d;
		for (int i = 0; i < d; i++)
		{
			cin >> num[i];
			if (num[i] > maxval)
				maxval = num[i];
		}

		int best = INT_MAX;
		for (int i = 1; i <= maxval; i++)
		{
			int tot = 0, cnt[1001];
			memset(cnt, 0, sizeof(cnt));
			for (int j = 0; j < d; j++)
			{
				if (num[j] <= i)
				{
					cnt[num[j]]++;
				}
				else
				{
					if (num[j] % i == 0)
					{
						tot += num[j] / i - 1;
						cnt[i] += num[j] / i;
					}
					else
					{
						tot += num[j] / i;
						cnt[i] += num[j] / i;
						cnt[num[j] % i]++;
					}
				}
			}

			for (int j = i; j > 0;j--)
			{
				if (cnt[j] != 0)
				{
					tot += j;
					break;
				}
			}
			if (tot < best)
				best = tot;
		}
		cout << "Case #" << ++kase << ": " << best << endl;
	}
	return 0;
}