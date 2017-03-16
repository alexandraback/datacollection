
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

int ans[100007];

int main()
{
	string name = "B-small";
	string path = "";

	freopen((path + name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);

	int test_cases;
	scanf("%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);

		double p = 2.0;
		double t = 0.0;
		double y = 0.0;

		while (1)
		{
			const double tx = x / p;
			const double tc = c / p + x / (p + f);

			if (tc < tx)
			{
				t += c / p;
				p += f;
			}
			else
			{
				t += tx;
				break;
			}
		}

		printf("Case #%d: %.7lf\n", test_case, t);
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}
