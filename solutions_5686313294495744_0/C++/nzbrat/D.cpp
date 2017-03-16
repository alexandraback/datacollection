# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <vector>
# include <queue>
# include <map>
# include <iostream>
# include <algorithm>

using namespace std;

int n;
pair <string, string> p[16];

int used[16];

int main ()
{
	int t, nt, i, j, k, cnta, cntb, lsta, lstb, ans = -1, crr;
	cin >> t;
	for (nt = 1; nt <= t; nt ++)
	{
		cin >> n;
		ans = -1;
		for (i = 0; i < n; i ++)
			cin >> p[i].first >> p[i].second;
		for (i = 0; i < (1 << n); i ++)
		{
			crr = 0;
			for (j = 0; j < n; j ++)
			{
				used[j] = ((1 << j) & i) > 0;
				crr += used[j] ^ 1;
			}
			for (j = 0; j < n; j ++)
			{
				if (used[j])
					continue;
				cnta = cntb = 0;
				lsta = lstb = -1;
				for (k = 0; k < n; k ++)
				{
					if (!used[k])
						continue;
					if (p[j].first == p[k].first)
					{
						cnta ++;
						lsta = k;
					}
					if (p[j].second == p[k].second)
					{
						cntb ++;
						lstb = k;
					}
				}
				if (!cnta || !cntb)
					break;
				if (cnta == 1 && cntb == 1 && lsta == lstb)
					break;
			}
			if (j < n)
				continue;
			ans = max (ans, crr);
		}
		printf ("Case #%d: ", nt);
		printf ("%d\n", ans);
	}
	return 0;
}

