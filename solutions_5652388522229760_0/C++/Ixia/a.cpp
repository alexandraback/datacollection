#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

const int max_iter = 100;
bool vis[10];

void mark(ll x) {
	while (x) {
		vis[x % 10] = 1;
		x /= 10;
	}
}

bool check() {
	for (int i = 0; i < 10; ++i) {
		if (!vis[i]) return false;
	}
	return true;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int _, cas = 1;
	scanf("%d", &_);
	while (_--) {
		printf("Case #%d: ", cas);
		cas++;
		memset(vis, 0, sizeof(vis));

		int n;
		scanf("%d", &n);
		if (n == 0) {
			puts("INSOMNIA");
		} else {
			ll x = n;
			for (int it = 0; it < max_iter; ++it) {
				mark(x);
				if (check()) break;
				x = x + n;
			}
			cout << x << endl;
		}
	}
	return 0;
}
