//be naame khodaa

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		int n;
		string s;
		cin >> n >> s;
		int ans = 0, stand = s[0] - '0';
		for (int j = 1; j <= n; j++)
		{
			ans += max(0, j-stand);
			stand = max(stand, j);
			stand += s[j]-'0';
		}
		cout << "Case #" << it << ": " << ans << endl;
	}
    return 0;
}
