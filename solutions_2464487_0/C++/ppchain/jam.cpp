#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const long long INF = 1000000000000000000LL;

int main() 
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("jam.out", "w", stdout);
	int ncas;
	scanf("%d", &ncas);
	long long r, t;
	for (int cas = 1; cas <= ncas; ++cas) {
		scanf("%lld%lld", &r, &t);
		long long low = 1, high = t / r / 2, mid, res;
		while (low <= high) {
			mid = (low + high) / 2;
			if ((t / 2 / mid < mid) || (t / mid < (2 * r - 1))) {
				high = mid - 1;
				continue;
			}
			long long val = 2 * mid * mid + (2 * r - 1) * mid - t;
			if (val == 0) {
				res = mid;
				break;
			}
			if (val < 0) {
				res = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		printf("Case #%d: %lld\n", cas, res);
	}
	//system("pause");
	return 0;
}
