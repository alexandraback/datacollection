#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k, n, T;	

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int x, y;
		cin >> n >> x >> y;
		printf("Case #%d: ", t);
		if (x < 0)
			x *= -1;
		int cur = (x + y) / 2;
		if (cur == 0)
		{
			puts("1.0");
			continue;
		}
		int before = 0;
		for(i = 0; i < cur; i++)
			before += 4 * i + 1;
		if (before >= n)
		{
			puts("0.0");
			continue;
		}
		n -= before;
		if (n > 4 * cur + 1)
		{
			puts("1.0");
			continue;
		}
		if (x == 0)
		{
			puts(n == cur * 4 + 1 ? "1.0" : "0.0");
			continue;
		}
		if (y >= n)
		{
			puts("0.0");
			continue;
		}
		if (n >= cur * 2 + y + 1)
		{
			puts("1.0");
			continue;
		}
		double ans = 0.0;
		double p = pow(0.5, n);
		for(i = 0; i <= y; i++)
		{
			ans += p;
			p = p * (n - i) / (i + 1);
		}
		printf("%lf\n", 1 - ans);
	}

	return 0;
}