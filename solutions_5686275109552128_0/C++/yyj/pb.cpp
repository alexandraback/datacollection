/*
 * pb.cpp
 *
 *  Created on: 2015年4月11日
 *      Author: ying
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<climits>
using namespace std;

#define N 1100
int d;
int num[N];

void solve (int numCases) {
	scanf ("%d", &d);
	int maxVal = 0;
	for (int i = 0; i < d; i++) {
		scanf ("%d", &num[i]);
		maxVal = max(maxVal, num[i]);
	}
	int ans = INT_MAX;
	for (int i = 1; i <= maxVal; i++) {
		int curAns = i;
		for (int j = 0; j < d; j++) {
			curAns += (num[j] - 1) / i;
		}
		ans = min(ans, curAns);
	}
	printf("Case #%d: %d\n", numCases, ans);
}

int main () {
	int k;
	scanf ("%d", &k);
	for (int i = 1; i <= k; i++) {
		solve (i);
	}
	return 0;
}


