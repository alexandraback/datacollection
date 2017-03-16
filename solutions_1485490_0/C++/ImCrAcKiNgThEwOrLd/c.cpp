#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, m;
pair<__int64, __int64> a[102], b[102];
__int64 sum[102][102];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			cin >> a[i].second >> a[i].first;
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= 100; ++j)
				sum[i][j] = sum [i - 1][j];
			cin >> b[i].second >> b[i].first;
			sum[i][b[i].first] += b[i].second;
		}
		for (int i = 1; i <= 100; ++i)
			sum[m + 1][i] = sum[m][i];
		__int64 ans = -1;
		if (n == 1)
			ans = min(a[1].second, sum[m][a[1].first]);
		if (n == 2)
		{
			for (int i = 1; i <= m + 1; ++i)
				ans = max(ans, min(sum[m + 1][a[2].first] - sum[i - 1][a[2].first], a[2].second) + min(sum[i - 1][a[1].first], a[1].second));
		}
		if (n == 3)
		{
			for (int j = 1; j <= m + 1; ++j)
			{
				__int64 mx = min(sum[m + 1][a[3].first] - sum[j - 1][a[3].first], a[3].second);
				ans = max(ans, max(min(sum[j - 1][a[1].first], a[1].second), min(sum[j -1][a[2].first], a[2].second)) + mx);
				for (int i = 1; i < j; ++i)
					ans = max(ans, min(sum[j][a[2].first] - sum[i - 1][a[2].first], a[2].second) + min(sum[i - 1][a[1].first], a[1].second)+ mx);
			}
		}
		cout << ans << endl;
	}
}