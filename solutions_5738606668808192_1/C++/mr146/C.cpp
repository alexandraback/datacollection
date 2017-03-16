#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;


long long powers[11][30];
int divisor[10];
int res[50];


void prec() {
	for(int i = 1; i <= 10; i++) {
		powers[i][0] = 1;
		for(int j = 1; j < 30; j++) {
			powers[i][j] = powers[i][j - 1] * i;
		}
	}
}


int powmod(int dig, int pw, int mod) {
	int res = 1;
	for(int i = 0; i < pw; i++) {
		res = res * dig % mod;
	}
	return res % mod;
}


int test(int digit, int mask, int n) {
	int curDig = 0;
	long long number = 0;
	while(mask) {
		if(mask & 1) {
			number += powers[digit][curDig];
		}
		curDig++;
		mask /= 2;
	}
	for(int t = 2; t <= min(number, (long long)100); t++) {
		if((powmod(digit, n - 1, t) + number % t) % t == 0)
			return t;
	}
	return 0;
}


void build(int n, int mask) {
	int cur = n - 1;
	while(mask) {
		res[cur] = (mask & 1);
		mask /= 2;
		cur--;
	}
	res[0] = 1;
}


void solve(int n, int brute, int bound) {
	int ans = 0;
	for(int i = 0; i < (1 << brute); i++) {
		int mask = i * 2 + 1;
		bool ok = true;
		for(int j = 2; j <= 10; j++) {
			divisor[j] = test(j, mask, n);
			if(divisor[j] == 0) {
				ok = false;
				break;
			}
		}
		if(ok) {
			build(n, mask);
			for(int j = 0; j < n; j++)
				printf("%d", res[j]);
			for(int j = 2; j <= 10; j++)
				printf(" %d", divisor[j]);
			printf("\n");
			ans++;
			if(ans == bound)
				return;
		}
	}
}


void solve(int tc) {
	printf("Case #%d:\n", tc);
	int n, j;
	scanf("%d%d", &n, &j);
	solve(n, n / 2, j);
}


int main() {
	prec();
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		solve(i + 1);
	}
	return 0;
}