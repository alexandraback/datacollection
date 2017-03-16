/*
 * Qa.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: suparsh14
 */

#include<bits/stdc++.h>

using namespace std;

int main() {

	int tc;
	int heights[2501];
	scanf("%d ", &tc);

	for (int i = 1; i <= tc; i++) {
		int n;
		memset(heights, 0, sizeof(heights));
		scanf("%d", &n);
		for (int j = 1; j <= (2 * n - 1); j++) {

			for (int l = 1; l <= n; l++) {
				int temp;
				scanf("%d", &temp);
				heights[temp]++;
			}
		}
		vector<int> x;
		for (int k = 1; k <= 2500; k++) {
			if (heights[k] % 2 == 1)
				x.push_back(k);
		}
		sort(x.begin(), x.end());
		printf("Case #%d: ", i);
		for (std::vector<int>::iterator it = x.begin(); it != x.end(); ++it)
			std::cout << *it << ' ';
		printf("\n");
	}

	return 0;
}

