#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

int cnt[20];
int gg;

void add(ll x) {
	while (x) {
		int y = x % 10;
		if (!cnt[y])
			cnt[y] = 1, --gg;
		x /= 10;
	}
}

void solve() {
	ll n;
	cin >> n;
	if (n == 0) {
		cout << "INSOMNIA\n";
		return;
	}
	for (int i = 0; i < 10; ++i)
		cnt[i] = 0;
	gg = 10;
	add(n);
	ll now = n;
	while (gg > 0)
		now += n, add(now);
	cout << now << "\n";
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int i = 1; i <= tt; ++i) {
		printf("Case #%d: ", i);
		solve();

	}
	return 0;
}


