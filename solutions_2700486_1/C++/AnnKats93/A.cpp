#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("b.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; tt++)
	{
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		if(x < 0)
			x = -x;
		if(x == 0 && y == 0 && n > 0)
		{
			printf("Case #%d: 1.0\n", tt + 1);
			continue;
		}
		int len = (x + y) / 2;
		int cn = 1;
		for(int i = 1, j = 1; i < len; i++, j += 2)
			cn += 2 * (j + 1) + 1;
		n -= cn;
		if(x == 0)
		{
			if(n < 2 * y + 1)
				printf("Case #%d: 0.0\n", tt + 1);
			else
				printf("Case #%d: 1.0\n", tt + 1);
			continue;
		}
		if(n <= y)
		{
			printf("Case #%d: 0.0\n", tt + 1);
			continue;
		}
		if(n >= len * 2 + 1 + y)
		{
			printf("Case #%d: 1.0\n", tt + 1);
			continue;
		}
		y++;
		long double ans = 0.0, cnk = 1, po = pow(0.5, y);
		for(int i = y; i <= n; i++)
		{
			ans += cnk * po;
			po *= 0.5;
			cnk = cnk * i / (i - y + 1); 
		}
		printf("Case #%d: %.8Lf\n", tt + 1, ans);
	}


	return 0;
}