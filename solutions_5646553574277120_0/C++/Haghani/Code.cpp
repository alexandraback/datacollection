#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 105;
long long a[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		long long m, n, k;
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		long long ans = 0, last = 1, p = 0;
		while (last <= k)
		{
			while (p < n && a[p] <= last)
			{
				last += a[p] * m;
				p++;
			}
			if (last > k)
				break;
			ans++;
			last += last * m;
		}
		cout << "Case #" << _ << ": " << ans << endl;
	}
	return 0;
}
