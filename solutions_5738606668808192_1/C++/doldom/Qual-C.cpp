#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

void printCoin(ll coin) {
	string ret;
	while (coin) {
		ret += (coin&1ll) + '0';
		coin >>= 1;
	}
	reverse(ret.begin(), ret.end());
	printf("%s", ret.c_str());
}

ll interpret(ll coin, int base) {
	if (base == 2) return coin;
	ll ret = 0, mul = 1;
	while (coin) {
		ret += (coin&1) * mul;
		mul *= base;
		coin >>= 1;
	}
	return ret;
}

int main() {
	freopen("qual\\C-large.in", "r", stdin);
	freopen("qual\\C-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		int n, j;
		scanf("%d%d", &n, &j);
		printf("Case #%d:\n", N);

		ll coin = (1ll<<(n/2-1)) + 1;
		for (int i=0; i<j; ++i, coin+=2) {
			printCoin(coin); printCoin(coin); printf(" ");
			for (int t=2; t<=10; ++t) {
				printf("%lld ", interpret(coin, t));
			}
			puts("");
		}
	}
}