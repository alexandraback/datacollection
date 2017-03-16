#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
using namespace std;


int main() {
	int cases;
	int caseid = 1;
	int D;
	int p[ 1005 ];

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &cases);
	while(cases--) {

		scanf("%d", &D);
		for(int i = 0; i < D; i++) {
			scanf("%d", &p[ i ]);
		}

		int ans = INT_MAX;
		for(int k = 1; k <= 1000; k++) {
			int sp = 0;
			for (int i = 0; i < D; i++) {
				if (p[i] > k) {
					sp += (int)ceil((double)p[i] / (double)k) - 1;
					//printf("[%d] %d\n", k, (int)ceil((double)p[i] / (double)k) - 1);
				}
			}
			ans = min(ans, sp + k);
		}
		printf("Case #%d: %d\n", caseid++, ans);
	}
	return 0;
}

