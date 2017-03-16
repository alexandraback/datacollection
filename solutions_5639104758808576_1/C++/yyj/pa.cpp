/*
 * pa.cpp
 *
 *  Created on: 2015年4月11日
 *      Author: ying
 */

#include<iostream>
#include<cstdio>
using namespace std;
#define N 1100

int s;
char num[N];

void solve (int numCases) {
	scanf ("%d %s", &s, num);
	int t = num[0] - '0';
	int ans = 0;
	for (int i = 1; i <= s; i++) {
		if (t < i) {
			ans++;
			t++;
		}
		t += num[i] - '0';
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


