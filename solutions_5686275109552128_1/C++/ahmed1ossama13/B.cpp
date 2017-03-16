#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	ios::sync_with_stdio(false);
	freopen("/home/ahmed_ossama/Desktop/Code jam/B/B-large.in", "r", stdin);
	freopen("/home/ahmed_ossama/Desktop/Code jam/B/Bsmart.out", "w", stdout);
	int t;
	int id = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int ans = a[n - 1];
		for (int bound = 1; bound <= 1000; bound++) {
			int tmp = bound;
			for (int j = 0; j < n; j++) {
				int x = a[j];
				tmp += x / bound;
				if (x % bound == 0)
					tmp--;
			}
			ans = min(ans, tmp);
		}
		cout << "Case #" << id++ << ": " << ans << endl;

	}
	return 0;
}

