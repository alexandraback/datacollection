#include <bits/stdc++.h>

using namespace std;

int T, p[1024], n;

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			ans = max(ans, p[i]);
		}
		for (int i = 1; i < ans; i++)
		{
			int c = 0;
			for (int j = 0; j < n; j++)
			{
				c += p[j] / i;
				if (p[j] % i == 0) c--;
			}
			ans = min(ans, i + c);
		}
		cout << "Case #" << C << ": " << ans << '\n';
	}
	return 0;
}

