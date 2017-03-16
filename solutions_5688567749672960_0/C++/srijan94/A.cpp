#include <cstdio>

using namespace std;

#define LIM 1000000

typedef long long int ll;

int ans[LIM + 1], N;

int min(int a, int b) {
	return (a < b ? a : b);
}

ll reverse(int x) {
	ll ret = 0;
	while(x > 0) {
		ret = ret * 10 + x % 10;
		x = x / 10;
	}
	return ret;
}

void init() {
	int i;
	ll rev;
	for(i = 1; i <= LIM; i++) ans[i] = 10 * LIM;
	ans[1] = 1;
	for(i = 1; i <= LIM; i++) {
		ans[i + 1] = min(ans[i + 1], ans[i] + 1);
		rev = reverse(i);
		if(rev <= LIM)
			ans[rev] = min(ans[rev], ans[i] + 1);
	}
}

int main(int argc, char const *argv[])
{
	freopen("iSA.in", "r", stdin);
	freopen("oSA.txt", "w", stdout);
	init();
	int tc, T;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		printf("Case #%d: %d\n", tc, ans[N]);
	}
	return 0;
}