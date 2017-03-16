#include <cstdio>
typedef long long ll;
int T, n, m;
void print(int x, int len) {
	for (int i = 1; i <= len; i++)
		printf("%d", (x>>(len-i))&1);
}
ll change(int x, int k) {
	if (x == 0) return 0;
	ll ans = change(x/2, k);
	return ans*k+x%2;
}
int main() {
	scanf("%d%d%d", &T, &n, &m);
	puts("Case #1:");
	int x = (1<<(n/2-1))+1;
	while (m--) {
		print(x, n/2);
		print(x, n/2);
		for (int k = 2; k <= 10; k++)
			printf(" %lld", change(x, k));
		puts("");
		x += 2;
	}
	return 0;
}
