#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int maxVal[31][2];

void precompute() {
	// assume for value 0, val = 0
	for (int i = 1; i <= 30; ++i) {
		int mean = i / 3;
		int sisa = i - mean * 3;
		
		switch (sisa) {
		case 2:
			maxVal[i][0] = mean + 1;
			maxVal[i][1] = mean + 2;
			break;
		case 1:
			maxVal[i][0] = mean + 1;
			maxVal[i][1] = mean + 1;
			break;
		case 0:
			maxVal[i][0] = mean;
			maxVal[i][1] = mean + 1;
			break;
		}
	}
}

int main() {
	int ntc;

	precompute();
	
	scanf("%d", &ntc);
	
	for (int tc = 1; tc <= ntc; ++tc) {
		int n, surp, least;
		scanf("%d %d %d",&n, &surp, &least);
		
		int value[n];
		
		for (int i = 0; i < n; ++i) {
			scanf("%d", &value[i]);
		}
		
		sort(value, value + n, greater<int>());
		
		int cnt = 0;
		for (int i = 0, j = 0; i < n; ++i) {
			//printf("value = %d %d\n", value[i], maxVal[value[i]][0]);
			if (maxVal[value[i]][0] >= least) {
				cnt++;
			} else if (maxVal[value[i]][1] >= least && j < surp) {
				cnt++;
				j++;
			}
		}
		
		printf("Case #%d: %d\n", tc, cnt);
	}
	return 0;
}
