#include <bits/stdc++.h>
using namespace std;

const int N = 1050;

int A[N], n;

void solve ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> A[i];
	int ans = ~0u >> 1;
	for (int ds = 1; ds <= 1000; ++ds)
	{
		int divTime = 0;
		for (int i = 1; i <= n; ++i)
		{
			divTime += max(0, (A[i] + ds - 1) / ds - 1);
		}
		ans = min(ans, divTime + ds);
	}
	static int ncase = 0;
	cout << "Case #" << ++ncase << ": " << ans << endl;
}

int main ()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int ncase;
	cin >> ncase;
	while (ncase--) solve();
	return 0;
}

