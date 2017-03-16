#include <bits/stdc++.h>
using namespace std;

bool sudah[10];
long long last;
int cnt;

int main() {
	int T;
	scanf("%d", &T);
	for (int z = 1; z <= T; ++z) {
		cnt = 0;
		long long n;
		scanf("%lld", &n);
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", z);
			continue;
		}
		last = -1;
		memset(sudah, false, sizeof sudah);
		int counter = 1;
		while (cnt < 10) {
			long long ncopy = n * counter;
			while (ncopy > 0) {
				int d = ncopy % 10;
				if (!sudah[d]) {
					sudah[d] = true;
					++cnt;
					if (cnt == 10) {
						last = n * counter;
						break;
					}
				}
				ncopy /= 10;
			}
			
			++counter;
		}
		
		printf("Case #%d: %lld\n", z, last);
	}
}
