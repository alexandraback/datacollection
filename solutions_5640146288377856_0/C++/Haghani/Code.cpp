#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int ans = (n - 1) * (m / k);
		while (m - k >= k)
		{
			m -= k;
			ans++;
		}
		if (m == k)
			ans += k;
		else
			ans += k + 1;
		cout << "Case #" << _ << ": " << ans << endl;
	}
	return 0;
}
