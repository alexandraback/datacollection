#include <iostream>

using namespace std;

const int MAXN = 1010;

int a[MAXN];

int main()
{
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		int n;
		cin >> n;
		int cmx = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			cmx = max(cmx, a[i]);
		}
		int ans = cmx;
		for (int mx = 1; mx <= cmx; mx++)
		{
			int add = 0;
			for (int i = 0; i < n; i++)
				add += (a[i] - 1) / mx;
			ans = min(ans, add + mx);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}
