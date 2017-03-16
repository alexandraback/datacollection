#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
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
int n, x, y;

double p[5000];
double pnext[5000];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%d %d %d", &n, &x, &y);
		x = abs(x);

		int side = 1;

		while(1)
		{
			if (side * 2 - 1 > n) break;
			n -= side * 2 - 1;
			side += 2;
		}

		if (x + y + 1 > side)
		{
			puts("0.0");
			continue;
		}

		if (x + y + 1 < side)
		{
			puts("1.0");
			continue;
		}

		for(int i = 0; i <= side; i++) p[i] = 0.0;
		p[0] = 1.0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= side; j++) pnext[j] = 0.0;

			for(int left = 0; left < side; left++)
			{
				if (left > i) continue;

				int right = i - left;

				if (left == side - 1)
				{
					// right only
					pnext[left] += p[left];
				}
				else
				if (right == side - 1)
				{
					// left only
					pnext[left + 1] += p[left];
				}
				else
				{
					// both ways
					pnext[left    ] += p[left] / 2.0;
					pnext[left + 1] += p[left] / 2.0;
				}
			}

			for(int j = 0; j <= side; j++)
			{
				p[j] = pnext[j];
				//printf("%.10lf, \n", p[j]);
				//cout << p[j] << ", ";
			}
			//puts("");
		}

		long double res = 0.0;
		for(int i = y + 1; i <= side; i++) res += p[i];

		if (res < 0) res = 0.0;

		printf("%.10lf\n", res);
		//cout << res << endl;
	}
	return 0;
}