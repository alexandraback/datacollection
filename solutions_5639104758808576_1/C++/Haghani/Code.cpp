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
		for (int i = 0; i <= n; i++)
		{
			char c;
			cin >> c;
			a[i] = c - '0';
		}
		int ans = 0, sum = a[0];
		for (int i = 1; i <= n; i++)
		{
			if (sum < i)
			{
				ans += i - sum;
				sum = i;
			}
			sum += a[i];
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
	return 0;
}
