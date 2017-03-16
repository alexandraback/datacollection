//be naame khodaa

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool pos[1005];
int coin[1005];

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		int c, d, v;
		cin >> c >> d >> v;
		for (int i = 0; i < d; i++)
			cin >> coin[i];
		fill(pos, pos + v + 1, false);
		pos[0] = true;
		for (int i = 0; i < (1 << d); i++)
		{
			int cur = 0;
			for (int j = 0; j < d; j++)
				if ((i >> j)&1)
					cur += coin[j];
			if (cur <= v)
				pos[cur] = true;
		}
		int ans = 0;
		for (int i = 1; i <= v; i++)
		{
			if (!pos[i])
			{
				ans++;
				for (int j = v; j >= i; j--)
					if (pos[j-i])
						pos[j] = true;
			}
		}
		cout << "Case #" << it << ": " << ans << endl;
	}
    return 0;
}
