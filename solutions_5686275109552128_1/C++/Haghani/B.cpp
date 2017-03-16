#include <iostream>
using namespace std;
const int MAX = 1005;
int a[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans = MAX;
		for (int i = 1; i < MAX; i++)
		{
			int res = 0, x = 0;
			for (int j = 0; j < n; j++)
			{
				res += (a[j] - 1) / i;
				if (a[j] >= i)
					x = i;
				else
					x = max(x, a[j]);
			}
			ans = min(ans, res + x);
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
	return 0;
}
