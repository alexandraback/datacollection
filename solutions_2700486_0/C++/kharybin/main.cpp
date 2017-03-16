#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

template <class T> T sqr(T x) { return x*x; }

const int INF = 1000*1000*1000;
const long long INF64 = sqr(static_cast<long long>(INF));
const double PI = acos(-1.0);

double C(int n, int k)
{
	double ret = 1;
	for(int i = 1; i <= k; ++i)
		ret = ret * (n-k+i) / i / 2.0;
	for(int i = 0; i < n-k; ++i)
		ret /= 2.0;
	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int testCaseCount;
	cin >> testCaseCount;
	for(int testCaseNumber = 1; testCaseNumber <= testCaseCount; ++testCaseNumber)
	{
		printf("Case #%d: ", testCaseNumber);
		int n, x, y;
		cin >> n >> x >> y;
		int h = 1;
		while ((2*h-1)*h <= n)
			++h;
		if (x < 0) x = -x;
		if ((x+y)/2 < h-1)
		{
			printf("1.0\n");
			continue;
		}
		if ((x+y)/2 >= h)
		{
			printf("0.0\n");
			continue;
		}
		int last = n - (2*h-3)*(h-1);
		double ans = 0;
		double pp = 1;
		for (int k = 0; k < 2*h-1; ++k)
			if (last - k < 2*h-2)
				pp -= C(last, k);
		for (int k = 2*h-1-x; k < 2*h-1; ++k)
		{
			if (last - k >= 2*h-1)
				continue;
			if (last - k == 2*h-2)
				ans += pp;
			else
				ans += C(last, k);
		}
		printf("%.7lf\n", ans);
	}
	return 0;
}