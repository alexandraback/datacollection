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

#define INF (2000000000)

const int lim = 10000100;

vector<long long> v;

bool palindrome(long long x) {

	long long orig = x, y = 0;
	while(x) {
		y *= 10;
		y += x % 10;
		x /= 10;
	}

	return orig == y;
}

void prepare() {

	int cnt = 0;

	for(int i = 1; i < lim; ++i) {
		long long x = i;
		x *= x;

		if (palindrome(i) && palindrome(x)) {
			v.push_back(x);
		}
	}

}

long long a, b;

void readTest() {
	scanf("%I64d%I64d", &a, &b);
}

void solveTest() {
	int cnt = 0;
	for(int i = 0; i < (int)v.size(); ++i) {
		if (a <= v[i] && v[i] <= b) {
			++cnt;
		}
	}
	printf("%d\n", cnt);
}

int main()
{
	freopen("C.in", "rt", stdin);

	prepare();

	bool submit = true;

	if (submit) {
		freopen("C.out", "wt", stdout);
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