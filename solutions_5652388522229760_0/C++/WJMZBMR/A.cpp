#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long int64;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int seen = 0;
		int x;
		cin >> x;
		if (x == 0) {
			printf("Case #%d: INSOMNIA\n", nc);
			continue;
		}
		int64 i;
		for (i = x;; i += x) {
			int64 t = i;
			while (t > 0) {
				seen |= 1 << (t % 10);
				t /= 10;
			}
			if (seen == 1023)
				break;
		}
		printf("Case #%d: %lld\n", nc, i);
	}
	return 0;
}
