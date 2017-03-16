#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 7;

ll ans[N];
bool mark[10];

int main()
{
	ios::sync_with_stdio(false);
	ans[0] = -1;
	for (int i=1; i<N; i++)
	{
		ll cnt = 10;
		memset(mark, 0, sizeof mark);
		ll t = 0;
		while (cnt)
		{
			t += i;
			ll x = t;
			while (x)
			{
				if (!mark[x % 10])
					mark[x % 10] = true, cnt--;
				x /= 10;
			}
		}
		ans[i] = t;
	}
	int t;
	cin >> t;
	for (int i=0; i<t; i++)
	{
		int x;
		cin >> x;
		cout << "Case #" << i+1 << ": ";
		if (ans[x] == -1)
			cout << "INSOMNIA";
		else
			cout << ans[x];
		cout << "\n";
	}
}
