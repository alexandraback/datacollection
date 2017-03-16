#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

long long a[105];
int c, d;
long long v;

void solve ()
{
	sort(a, a + d);

	long long upVal = 0;
	int ans = 0;
	for (int i = 0; ; ) {
		if (upVal >= v)
			break;

		if (i == d || a[i] > upVal + 1) {
			ans++;
			upVal = upVal + (upVal + 1) * c;
		} else {
			upVal = upVal + a[i] * c;
			i++;
		}
	}
	
	printf("%d", ans);
}

int main ()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test_amount, test_num;

	scanf("%d\n", &test_amount);
	for (test_num = 0; test_num < test_amount; test_num++)
	{
		if (test_num)
			printf("\n");

		printf("Case #%d: ", test_num + 1);

		// input

		scanf("%d%d%lld", &c, &d, &v);
		for (int i = 0; i < d; i++) {
			scanf("%lld", &a[i] );
		}

		// #input

		solve();
	}

	return 0;
}