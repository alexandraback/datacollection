#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

const double pi = acos(-1.0);
long long r, t;

long long Solve()
{
	long long L = 0, R = 2000000000, mid, ans = 0;
	long long u;
	while (L <= R) {
		mid = (L + R) / 2;
		u = (long long)(2*r-3)*mid + 2*(long long)(mid)*(mid+1);
		double H = double(2*r-3)*mid + 2*(double)(mid)*(mid+1);
		if (u <= t && H <= t) {
			ans = mid;
			L = mid + 1;
		} else {
			R = mid - 1;
		}
	}
	return ans;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int TextN = 0, TT = 0;
	scanf("%d", &TextN);
	while (TextN--) {
		cin >> r >> t;
		printf("Case #%d: %lld\n",++TT, Solve());
	}
	return 0;
}
