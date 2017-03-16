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

ll go[300];
ll k, c, s;

void solve() {
	set<ll> ss;
	cin >> k >> c >> s;
	if (s * c < k) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	int bl = (k - 1) / c + 1;
	for (int i = 0; i < bl; ++i)
		go[i] = 0;
	for (int i = 0; i < k; ++i) {
		int x = i / c;
		go[x] = go[x] * k + i;
	}
	for (int i = 0; i < bl; ++i)
		ss.insert(go[i]);
	for (ll i: ss)
		cout << i + 1 << " ";
	cout << "\n";
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


