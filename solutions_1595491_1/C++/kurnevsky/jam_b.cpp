#include <iostream>

using namespace std;

int main()
{
	int t, n, s, p;
	int x;
	int ans;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> s >> p;
		ans = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			
			if (x / 3 + (x % 3 > 0 ? 1 : 0) >= p)
			{
				ans++;
			}
			else if (x > 1 && x / 3 + (x % 3 > 1 ? 2 : 1) >= p && s > 0)
			{
				ans++;
				s--;
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}

	return 0;
}
