
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <memory.h>
using namespace std;

double a[1024];
double b[1024];

int main()
{
	string name = "D-small";
	string path = "";

	freopen((path + name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);

	int test_cases;
	scanf("%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%lf", a+i);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", b+i);
		}
		sort(a,a+n);
		sort(b,b+n);

		int y = 0;
		int i = 0;
		int j = 0;
		while (i < n && j < n)
		{
			if (a[i] < b[j])
			{
				i++;
				y++;
			}
			j++;
		}
		y = n - y;

		int x = 0;
		i = 0;
		j = 0;
		while (i < n && j < n)
		{
			if (a[i] > b[j])
			{
				j++;
				x++;
			}
			i++;
		}

		printf("Case #%d: %d %d\n", test_case, x, y);

	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}
