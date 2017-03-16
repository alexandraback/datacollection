#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

#define INF (INT_MAX/3)

using namespace std;

int main()
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int t = 0; t < ntest; t++) {
		int A, n;
		scanf("%d %d", &A, &n);

		vector <int> others(n, 0);
		
		for (int i = 0; i < n; i++)
			scanf("%d", &others[i]);

		int result = INF;

		for (int s = 0; s < (1<<n); s++) {
			vector <int> stay;
			for (int i = 0; i < n; i++)
				if (s & (1<<i))
					stay.push_back(others[i]);

			int cost = n-stay.size();
			int oursize = A;

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

		printf("Case #%d: %d\n", t+1, result);
	}

	return 0;
}
