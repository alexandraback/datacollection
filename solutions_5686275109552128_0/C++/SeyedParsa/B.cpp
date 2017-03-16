//be naame khodaa

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int p[1005];

int main()
{
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		int D;
		cin >> D;
		for (int i = 0; i < D; i++)
			cin >> p[i];
		int ans = 1000;
		for (int mx = 1; mx <= 1000; mx++)
		{
			int cost = 0;
			for (int j = 0; j < D; j++)
				cost += (p[j]-1)/mx;
			ans = min(ans, cost + mx);
		}
		cout << "Case #" << it << ": " << ans << endl;
	}
    return 0;
}
