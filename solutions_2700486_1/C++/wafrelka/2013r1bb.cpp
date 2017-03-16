#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long int64;
const int inf = (int)1e9;

double calc(int n, int k)
{
	double v = 1;

	for(int i = 0; i < k; ++i)
		v *= (double)((n - k + 1) + i) / (double)(k - i) * 0.5;
	for(int i = k; i < n; ++i)
		v *= 0.5;

	return v;
}

int main()
{
	int testcase;

	scanf("%d", &testcase);

	for(int casenum = 1; casenum <= testcase; ++casenum) {

		int n, x, y;
		double ans = 0;

		scanf("%d%d%d", &n, &x, &y);

		int midy = abs(x) + y;
		int level = midy / 2;

		int understone = level + (level * (level - 1)) / 2 * 4;
		int allstone = level * 4 + 1;
		int leftstone = y - 0;

		//printf("%d %d %d\n", understone, allstone, leftstone);

		if(understone + leftstone >= n) {

			ans = 0;

		} else if(understone + allstone <= n) {

			ans = 1;

		} else if(abs(x) == 0) {

			ans = 0;

		} else {

			int remain = n - understone;
			int half = (allstone - 1) / 2;

			for(int k = 0; k <= remain; ++k) {
				int right = min(half, remain - k);
				if(remain - right > leftstone)
					ans += calc(remain, k);
			}
		}

		printf("Case #%d: %.10f\n", casenum, ans);
	}

	return 0;
}

/* ハラスメントに負けず */
/* 0完太陽にも負けず */
/* はやく人権を獲得したい */
