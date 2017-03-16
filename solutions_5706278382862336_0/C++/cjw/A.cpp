#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

bool check(int p, int q)
{
	int pp = p, qq = q;

	while ((qq % 2 == 0) && (qq = qq / 2) > pp) ;

	if (pp == qq) return true;
	if (qq != 1 && qq % 2 == 1) return false;
	
	pp = pp - qq;
	if (qq % 2 == 1)
		return false;
	else
		check(pp, qq);
}

int main()
{
	int T;

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int P = 0, Q = 0;

		scanf("%d/%d", &P, &Q);

		if (Q % 2 == 1)
		{
			cout << "Case #" << t << ": impossible" << endl;
			continue;
		}
		else
		{
			if (P != 1 && Q % P == 0)
			{
				int x = Q / P;
				double n = log2(x);
				cout << "Case #" << t << ": " << n << endl;
				continue;
			}
			else
			{
				int ans = 1;

				while ((Q % 2 == 0) && (Q = Q / 2) > P)
					ans++;

				if (P != Q)
				{
					P = P - Q;

					if (check(P, Q)) cout << "Case #" << t << ": " << ans << endl;
					else cout << "Case #" << t << ": impossible" << endl;
				}
				else
				{
					cout << "Case #" << t << ": " << ans << endl;
				}
			}
		}
	}

	return 0;
}
