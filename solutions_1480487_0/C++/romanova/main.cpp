#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int n, t, s[205];
	double x;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt)
	{
		scanf("%d", &n);
		x = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &s[i]);
			x += s[i];
		}
		printf("Case #%d: ", tt+1);
		for(int i = 0; i < n; ++i)
		{
			double l = 0, r = 1, m;
			while(fabs(r-l) > 1e-9)
			{
				m = (l+r) / 2;
				double xx = s[i] + x * m;
				double y = 1 - m, yy;
				bool ok = 1;
				for(int j = 0; j < n; ++j)
				{
					if(i == j || s[j] >= xx)
						continue;
					yy = (xx-s[j]) / x;
					if(yy > y)
					{
						ok = 0;
						break;
					}
					y -= yy;
				}
				if(ok)
					l = m;
				else
					r = m;
			}
			printf("%.7lf ", m*100);
		}
		printf("\n");
	}

	return 0;
}

/*

int main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);


	return 0;
}

*/