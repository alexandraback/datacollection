#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <functional>
#include <climits>
#include <cassert>
#include <list>

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))

using namespace std;
typedef long long ll;

struct hunter
{
	double pos;
	double speed;
	hunter(double _pos, double _speed)
	{
		pos = _pos;
		speed = _speed;
	}
};

bool cmp(hunter a, hunter b)
{
	return a.speed < b.speed;
}

vector<hunter> a;

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tests;
	scanf("%d", &tests);

	for (int q = 0; q < tests; q++)
	{
		a.clear();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			double pos;
			scanf("%lf", &pos);
			int h;
			double speed;
			scanf("%d", &h);

			scanf("%lf", &speed);
			for (int j = 0; j < h; j++)
			{
				a.push_back(hunter(pos, 360.0 / speed));
				speed = speed + 1.0;
			}
		}
		int ans = 1;
		
		if (a.size() <= 1 || (a.size() == 2 && fabs(a[0].speed - a[1].speed) < 1e-9))
		{
			ans = 1;
		}

		if (ans == 1)
		{
			sort(a.begin(), a.end(), cmp);
			reverse(a.begin(), a.end());

			double deer_time = max((360.0 - a[0].pos) / a[0].speed, (360.0- a[1].pos) / a[1].speed);

			double dead_time;
			if (a[0].pos < a[1].pos)
			{
				double speed = a[0].speed - a[1].speed;
				dead_time = (a[1].pos - a[0].pos + 360.0) / speed;
			}
			else
			{
				double speed = a[0].speed - a[1].speed;
				dead_time = (360.0 - a[0].pos + a[1].pos) / speed;
			}

			if (deer_time > dead_time || fabs(dead_time - deer_time) < 1e-9)
			{
			}
			else
				ans = 0;
		}

		printf("Case #%d: %d\n", q + 1, ans);
	}


	return 0;
}