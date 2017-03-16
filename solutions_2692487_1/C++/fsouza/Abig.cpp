#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

#define INF (10000000000000000LL)

typedef long long lint;

using namespace std;

int main()
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int t = 0; t < ntest; t++) {
		lint A;
		int n;
		scanf("%lld %d", &A, &n);

		vector <lint> others(n, 0);
		
		for (int i = 0; i < n; i++)
			scanf("%lld", &others[i]);

		sort(others.begin(), others.end());

		lint result = INF;

		for (int before = 0; before <= n; before++) {
			vector <lint> stay;

			for (int i = 0; i < before; i++)
				stay.push_back(others[i]);

			lint cost = n-stay.size();
			lint oursize = A;

			sort(stay.begin(), stay.end());

			for (int i = 0; i < stay.size(); i++) {
				if (oursize == 1 && oursize <= stay[i]) {
					cost = INF;
					break;
				}
				while (oursize <= stay[i]) {
					oursize += oursize-1;
					cost ++;
				}
				oursize += stay[i];
			}

			result = min(result, cost);
		}

		printf("Case #%d: %lld\n", t+1, result);
	}

	return 0;
}
