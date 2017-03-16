//be naame khodaa

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		ll ans = (c/w*(r-1)) + c/w + w - (c%w == 0);
		cout << "Case #" << it << ": " << ans << endl;
	}
    return 0;
}
