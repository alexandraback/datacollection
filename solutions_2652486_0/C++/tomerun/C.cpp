#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

int R,N,M,K;

int count(int& v, int div){
	int ret = 0;
	while(v % div == 0) {
		v /= div;
		++ret;
	}
	return ret;
}

void solve() {
	scanf("%d %d %d %d", &R, &N, &M, &K);
	for (int r = 0; r < R; ++r) {
		int c2 = 0;
		int c3 = 0;
		int c5 = 0;
		bool odd2 = false;
		for (int k = 0; k < K; ++k) {
			int v;
			scanf("%d", &v);
			int count2 = count(v, 2);
			odd2 =  odd2 || count2 % 2 != 0;
			c2 = max(c2, count2);
			c3 = max(c3, count(v, 3));
			c5 = max(c5, count(v, 5));
		}
		int all = c3 + c5 + c2 / 2;
		for (int i = 0; i < c3; ++i) {
			printf("3");
		}
		for (int i = 0; i < c5; ++i) {
			printf("5");
		}
		for (int i = 0; i < c2 / 2; ++i) {
			printf("4");
		}
		if (odd2) {
			printf("2");
			++all;
		}
		for (int i = all; i < N; ++i) {
			printf("2");
		}
		printf("\n");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		printf("Case #%d:\n", tc);
		solve();
	}
}
