#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char st[2000];

void work() {
	scanf("%d%s", &n, st);
	int sum = 0;
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int dig = st[i] - '0';
		if (sum < i) {
			ans += i - sum;
			sum = i;
		}
		sum += dig;
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
