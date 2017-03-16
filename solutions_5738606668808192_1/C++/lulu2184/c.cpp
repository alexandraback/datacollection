#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[40];
int total;

bool check(int a[40], int base) {
	long long x = 1;
	long long num = 0;
	for (int i = 0; i < n; i++) {
		num += x * a[i + 1];
		x *= base;
	}
	for (int i = 2; i <= 20; i++) {
		if (num % i == 0) {
			printf(" %d", i);
			return true;
		}
	}
	return false;	
}

bool check(int a[40]) {
	for (int base = 2; base <= 10; base ++) {
		if (!check(a, base)) return false;
	}
	return true;
}

void dfs(int x, int cnt, int a[40]) {
	if (x == 1) return;
	if (x == 2) {
		a[2] = a[1] = 1;
		if ((cnt + 1) % 3 != 0) return;
		for (int i = n; i >= 1; i--) printf("%d", a[i]);
		printf(" 3 2 5 2 7 2 3 2 11\n");
		// if (!check(a)) {
		// 	printf("FALSE\n");
		// 	while (true);
		// }
		total++;
		if (total >= 500) exit(0);
		return;
	}
	a[x] = 0;
	dfs(x - 1, cnt, a);
	a[x] = a[x - 1] = 1;
	dfs(x - 2, cnt + 1, a);
}

int main() {
	total = 0;
	n = 32;
	printf("Case #1:\n");
	a[n] = a[n - 1] = 1;
	dfs(n - 2, 0, a);

	return 0;
}