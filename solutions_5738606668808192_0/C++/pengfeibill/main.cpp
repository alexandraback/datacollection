#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	long long t;
	cin >> t;
	cout << "Case #1:" << endl;
	long long n, j;
	cin >> n >> j;
	if (n == 16) {
		for (long long i = 0; i < j; i++) {
			long long b = (1 << 7) + (i << 1) + 1;
			for (long long mask = (1 << 7); mask; mask >>= 1)
				cout << ((b & mask) ? 1 : 0);
			for (long long mask = (1 << 7); mask; mask >>= 1)
				cout << ((b & mask) ? 1 : 0);
			for (long long base = 2; base <= 10; base++) {
				long long num = 0;
				for (long long mask = (1 << 7); mask; mask >>= 1)
					num = num * base + ((b & mask) ? 1 : 0);
				cout << " " << num;
			}
			cout << endl;
		}
	} else if (n == 32) {
		for (long long i = 0; i < j; i++) {
			long long b = (1 << 15) + (i << 1) + 1;
			for (long long mask = (1 << 15); mask; mask >>= 1)
				cout << ((b & mask) ? 1 : 0);
			for (long long mask = (1 << 15); mask; mask >>= 1)
				cout << ((b & mask) ? 1 : 0);
			for (long long base = 2; base <= 10; base++) {
				long long num = 0;
				for (long long mask = (1 << 15); mask; mask >>= 1)
					num = num * base + ((b & mask) ? 1 : 0);
				cout << " " << num;
			}
			cout << endl;
		}
	}
	return 0;
}