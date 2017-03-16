#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		if (n < 3 || m < 3)
		{
			printf("%d\n", k);
			continue;
		}

		int res = (n + m) * 2 - 4;

		res = min(res, k);

		for(int w = 0; w < n; w++)
			for(int h = 0; h < m; h++)
				for(int d = 0; ;d++)
				{
					if (2 * d + w + 1 > n) break;
					if (2 * d + h + 1 > m) break;
					int rect = (2 * d + w + 1) * (2 * d + h + 1);
					int corner = d * (d + 1) / 2;
					int inside = rect - 4 * corner;

					int cost = 2 * (w + 1) + 2 * (h + 1) + (d - 1) * 4;
					if (d == 0)
					{
						if (w == 0) cost = h + 1;
						else
							if (h == 0) cost = w + 1;
					}
					
					if (inside < k) 
					{
						cost += k - inside;
					}

					//if (cost < res) printf("w = %d, h = %d, d = %d, cost = %d\n", w, h, d, cost);
					res = min(res, cost);
				}

		printf("%d\n", res);
	}
	return 0;
}