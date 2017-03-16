#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int testCase;
	scanf ("%d", &testCase);
	int n, sum;
	int a[500];
	for (int t = 1; t <= testCase; t++)
	{
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		printf("Case #%d: ", t);
		for (int i = 0; i < n; i++)
		{
			double l = 0;
			double r = 100;
			while (r - l > 1e-8)
			{
				double m = (l + r) / 2;
				double myScore = a[i] + m / 100 * sum;
				double tot = 0;
				double tmp = 0;
				for (int j = 0; j < n; j++)
					if (i != j)
					{
						tmp = myScore - a[j];
						if (tmp > 0)
							tot += (myScore - a[j]) * 100 / sum;
					}
				if (tot < 100 - m)
					l = m;
				else
					r = m;
			}
			printf("%.8lf ", l);
		}
		printf("\n");
	}
	return 0;
}