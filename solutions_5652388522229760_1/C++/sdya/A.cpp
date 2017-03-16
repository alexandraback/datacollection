#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <bitset>
#include <ctime>

using namespace std;

bitset<10> getDigits(long long n) {
	bitset<10> res;
	if (n == 0) {
		res[0] = 1;
		return res;
	}
	while (n) {
		res[n % 10] = 1;
		n /= 10;
	}
	return res;
}

void solve(int test) {
	int n;
	scanf("%d", &n);
	bitset<10> res;
	if (n == 0) {
		printf("Case #%d: INSOMNIA\n", test);
		return;
	}
	for (long long i = 1; i <= 1000000; ++i) {
		res |= getDigits(i * (long long)(n));
		if (res.count() == 10) {
			printf("Case #%d: %lld\n", test, i * (long long)(n));
			return;
		}
	}
	cerr << "More than 1000000 iters" << endl;
	printf("Case #%d: INSOMNIA\n", test);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve(i + 1);
		cerr << i + 1 << ": " << clock() << endl;
	}
	return 0;
}