#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

const int BIT = 32;
long long maxn = 1ll << 32;
long long minn = 1ll << 31;
int visp[10000005], pr[10000005], nPr;
int divs[16];

void primeTable(int N) {
	nPr = 0;
	visp[0] = visp[1] = 1;
	for (int i = 2; i < N; ++i) if (!visp[i]) {
		pr[nPr++] = i;
		for (int j = i * 2; j < N; j += i) {
			visp[j] = 1;
		}
	}
}

bool check(ll x) {
	for (int bas = 2; bas <= 10; ++bas) {
		bool flag = true;
		for (int i = 0; i < nPr; ++i) {
			if (pr[i] >= x) return false;
			ll bott = minn;
			ll remain = 0;
			for (int b = 0; b < BIT; ++b) {
				remain = remain * bas % pr[i];
				if (x & bott) remain += 1;
				bott >>= 1ll;
			}
			remain %= pr[i];
			if (remain == 0) {
				flag = false;
				divs[bas] = pr[i];
				break;
			}
		}
		if (flag) return false;
	}
	return true;
}

void binaryPrint(ll x) {
	ll bott = minn;
	for (int b = 0; b < BIT; ++b) {
		if (x & bott) putchar('1');
		else putchar('0');
		bott >>= 1ll;
	}
}

int main() {
	// freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	primeTable(10000005);

	int _, cas = 1;
	scanf("%d", &_);
	while (_--) {
		printf("Case #%d:\n", cas);
		cas++;

		int n, J;
		scanf("%d%d", &n, &J);
		int count = 0;
		for (ll i = minn + 1; i < maxn; i += 2) {
			if (check(i)) {
				binaryPrint(i);
				for (int j = 2; j <= 10; ++j) {
					printf(" %d", divs[j]);
				}
				printf("\n");
				count++;
				if (count == J) break;
			}
		}
	}
	return 0;
}