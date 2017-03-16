#include <iostream>
#include <cstdio>
#include <vector>


bool used[11];


void process(int n) {
	while(n) {
		used[n % 10] = true;
		n /= 10;
	}
}


bool ok() {
	for(int i = 0; i < 10; i++) {
		if(!used[i]) {
			return false;
		}
	}
	return true;
}


void solve(int tc) {
	memset(used, false, sizeof(used));
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 100; i++) {
		int m = i * n;
		process(m);
		if(ok()) {
			printf("Case #%d: %d\n", tc, m);
			return;
		}
	}
	printf("Case #%d: INSOMNIA\n", tc);
}


int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i + 1);
}