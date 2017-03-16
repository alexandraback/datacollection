/*
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
typedef long long LL;
bool has[10];

bool inline cansleep() {
	for (int i = 0; i < 10; i++) {
		if (!has[i]) {
			return false;
		}
	}
	return true;
}

int work(int N) {
	memset(has, false, sizeof(has));
	for (int i = 1; i <= 100; i++) {
		int m = N * i;
		while (m > 0) {
			has[m % 10] = true;
			m = m / 10;
		}
		if (cansleep()) {
			return i * N;
		}
	}
	return -1;
}

void test() {
	for (int N = 1; N <= 1000000; N++) {
		int ret = work(N);
		if (ret >= 0) {
			//printf("%d, %d\n", N, ret);
		} else {
			printf("%d, INSOMNIA\n", N);
		}
	}
	exit(0);
}

int main() {
//	test();
	int T, N;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		scanf("%d", &N);
		int ret = work(N);
		if (ret >= 0) {
			printf("%d\n", ret);
		} else {
			printf("INSOMNIA\n");
		}
	}
	return 0;
}


