#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int cache[1000001];

int rev(int n) {
	int ret = 0;
	while (n) {
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

void precal() {
	cache[0] = 0;
	for (int i=1; i<1000001; ++i) {
		cache[i] = cache[i-1] + 1;
		int ri = rev(i);
		if (i > ri && rev(ri) == i)
			cache[i] = min(cache[i], cache[ri]+1);
	}
}

int main() {
	precal();
	freopen("r1b\\A-small-attempt1.in", "r", stdin);
	freopen("r1b\\A-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", N);
		printf("%d\n", cache[n]);
	}
}