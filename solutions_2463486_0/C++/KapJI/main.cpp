#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<long long> poly;

bool isPolyndrome(long long a) {
	long long b = 0, t = a;
	while (t) {
		b = b * 10 + t % 10;
		t /= 10;
	}
	return a == b;
}

int solve() {
	long long l, r;
	cin >> l >> r;
	int li = lower_bound(poly.begin(), poly.end(), l) - poly.begin();
	int ri = upper_bound(poly.begin(), poly.end(), r) - poly.begin();
	
	return ri - li;
}

void init() {
	for (int i = 1; i <= 10000000; ++i) {
		if (isPolyndrome(i) && isPolyndrome(1LL * i * i)) {
			//cout << 1LL * i * i << endl;
			poly.push_back(1LL * i * i);
		} 
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: %d\n", i + 1, solve());
	}
	return 0;
}