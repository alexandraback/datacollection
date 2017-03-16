#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\wayne\\Downloads\\input.txt", "r", stdin);
	//freopen("C:\\Users\\wayne\\Downloads\\output.txt", "w", stdout);
	//freopen("C:\\Users\\wayne\\Downloads\\C-small-1-attempt0.in", "r", stdin);
	//freopen("C:\\Users\\wayne\\Downloads\\Small-output.out", "w", stdout);
	freopen("C:\\Users\\wayne\\Downloads\\C-small-2-attempt2.in", "r", stdin);
	freopen("C:\\Users\\wayne\\Downloads\\Small-2-output.out", "w", stdout);
	int t, r, n, m, k, v[12], g[9], num, size, random;

	cin >> t >> r >> n >> m >> k;
	cout << "Case #1:\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 1; j <= 8; j++)
			g[j] = 0;
		size = 0;
		for (int j = 0; j < k; j++)
			cin >> v[j];
		sort(v, v + k);
		for (int j = k - 1; j >= 0; j--)
		{
			num = v[j];
			while (num > 1 && size < n)
			{
				for (int k = m; k >= 2; k--)
					if (num % k == 0)
					{
						if (rand() % 2 == 0)
							continue;
						g[k]++;
						num /= k;
						size++;
						break;
					}
			}
		}
		if (size == 0)
		{
			random = rand() % (m - 1) + 2;
			for (int j = 1; j <= n; j++)
				cout << random;
		}
		else
		{
			for (int j = 2; j <= 8; j++)
				for (int k = 1; k <= g[j]; k++)
					cout << j;
		}
		cout << endl;
	}
	return 0;
}