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

int w, r, c;

void solve ()
{
	int ans = (r - 1) * (c / w);

	int rem = c;
	while (rem >= w * 2) {
		ans++;
		rem -= w;
	}
	if (rem == w)
		ans += w;
	else
		ans += w + 1;

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

		scanf("%d%d%d", &r, &c, &w);

		// #input

		solve();
	}

	return 0;
}