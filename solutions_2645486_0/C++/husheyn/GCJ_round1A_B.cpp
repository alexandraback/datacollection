#include <iostream>
#include <string.h>

using namespace std;

typedef long long LL;

int T;
LL E, R, N;
LL v[10005];

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> E >> R >> N;
		for(int i = 0; i < N; i++) cin >> v[i];
		int cur = E;
		LL ans = 0;
		for(int i = 0; i < N; i++)
		{
			int j = i + 1;
			while (j < N && v[i] > v[j]) j++;
			if (j == N)
			{
				ans += v[i] * cur;
				cur = 0;
			}
			else
			{
				LL t = cur + R * (j - i) - E;
				if (t > 0)
				{
					if (t <= cur)
					{
						ans += v[i] * t;
						cur = cur - t;
					}
					else
					{
						ans += v[i] * cur;
						cur = 0;
					}
				}
			}
			cur += R;
			if (cur > E) cur = E;
			//cout << ans << " " << cur << endl;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
