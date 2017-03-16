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

int cnt[3000];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n - 1; ++i)
		for (int j = 0; j < n; ++j) {
			int a;
			scanf("%d", &a);
			cnt[a] ^= 1;
		}
	for (int i = 0; i <= 2600; ++i)
		if (cnt[i])
			cout << " " << i;
	cout << "\n";
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i) {
		printf("Case #%d:", i + 1);
		solve();
	}
	return 0;
}


