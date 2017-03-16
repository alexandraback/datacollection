#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
char a[N][N];

void solve() {
	long long m;
	cin >> n >> m;
	if(m > (1LL << (n - 2))) {
		puts("IMPOSSIBLE");
		return;
	}
	puts("POSSIBLE");
	if(m == (1LL << (n - 2))) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i < j) {
					printf("1");
				} else {
					printf("0");
				}
			}
			puts("");
		}
		return;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i < j) {
				if(j == n) {
					if(i > 1 && (m & (1LL << (i - 2)))) {
						printf("1");
					} else {
						printf("0");
					}
				} else {
					printf("1");
				}
			} else {
				printf("0");
			}
		}
		puts("");
	}
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}