#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, x, y) for(int i = x; i < y; ++ i)
#define pb push_back
#define mk make_pair

bool b[15];

void solve() {
	int n;
	scanf("%d", &n);
	if (n == 0) {
		puts("INSOMNIA");
		return;
	}
	int c = 0;
	FOR(i,0,10)
		b[i] = false;
	int x = 0;
	while (c < 10) {
		x += n;
		for (int y = x; y > 0; y /= 10) {
			int z = y % 10;
			if (!b[z]) {
				b[z] = true;
				++c;
			}
		}
	}
	assert(c == 10);
	printf("%d\n", x);
}

int main() {
#ifdef LOCAL
	freopen("in","r",stdin);
#endif
	int T, Case = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++Case);
		solve();
	}
	return 0;
}
