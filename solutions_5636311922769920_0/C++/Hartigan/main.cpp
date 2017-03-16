#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <bitset>

using namespace std;

int t, n;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cout << "Case #" << i + 1 << ":";
		int k, c, s;
		cin >> k >> c >> s;

		if (k == 1)
		{
			cout << ' ' << 1 << endl;
			continue;
		}

		int p = (k + c - 1) / c;

		if (s < p)
		{
			cout << " IMPOSSIBLE";
		}
		else
		{
			long long sum = 1;
			for (int j = 0; j < c; j++)
			{
				sum *= k;
			}

			int b = 1;

			for (int j = 0; j < p; j++)
			{
				long long cur_sum = sum;
				long long ans = 0;

				for (int jj = 0; jj < c; jj++)
				{
					cur_sum /= k;
					ans += (b - 1) * cur_sum;
					if (b == k) break;
					b++;
				}

				if (ans + 1 > sum)
				{
					int bb = 5;
					bb++;
				}

				cout << ' ' << ans + 1;
			}
		}

		cout << endl;
	}

	return 0;
}