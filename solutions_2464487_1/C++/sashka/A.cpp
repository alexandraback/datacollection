#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

#pragma comment(linker, "/STACK:36777216")

#define INF (2000000000)

long long r, T;

void readTest() {
	scanf("%lld%lld", &r, &T);
}

void solveTest() {

	long long L = 0, R = 10000000000LL;

	while(R - L > 1) {
		long long M = (L + R) >> 1;

		long long q = 2 * (r + M) - 1;
		if (q > T / M) {
			R = M;
		} else {
			L = M;
		}
	}

	printf("%lld\n", L);

}

int main()
{
	freopen("A.in", "rt", stdin);

	bool submit = true;

	if (submit) {
		freopen("A.out", "wt", stdout);
	}

	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		readTest();
		printf("Case #%d: ", tt + 1);
		solveTest();
		if (submit) {
			cerr << "Case " << tt + 1 << " done\n";
		}
	}
	return 0;
}