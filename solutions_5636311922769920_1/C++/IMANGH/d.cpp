#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);

	int __;
	cin >> __;
	for (int _ = 0; _ < __; _++)
	{
		cout << "Case #" << _ + 1 << ": ";
		ll k, c, s;
		cin >> k >> c >> s;
		ll ans = (k + c - 1) / c;
		if (s < ans)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (ll i=0; i<k; i += c)
		{
			ll num = 0;
			ll t = 1;
			for (ll j=c-1; j>=0; j--)
				num += min(i + j, k-1) * t, t *= k;
			num++;
			cout << num << " ";
		}
		cout << "\n";
	}

	return 0;
}
