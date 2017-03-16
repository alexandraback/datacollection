#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

bool isPala(long long c) {
	long long d = 0, t = c;
	while (t) {
		d *= 10;
		d += t % 10;
		t /= 10;
	}
	return d == c;
}

int memo[10000001];


void init() {
	int res = 0;
	for (long long i = 1; i <= 10000000; ++i) {
		long long curr = i * i;
		if (isPala(i) && isPala(curr)) {
			++res;
		}
		memo[i] = res;
	}
}

int solve(long long C) {
	long long sqrtC = sqrt(double(C));
	return memo[sqrtC];
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	init();
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		long long A, B;
		cin >> A >> B;
		

		cout << "Case #" << t << ": " << solve(B) - solve(A - 1) << endl;
	}

	return 0;
}
