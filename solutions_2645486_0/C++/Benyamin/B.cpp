// In The Name of God
#include <iostream>
#include <algorithm>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
typedef long long ll;

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

int T, e, r, n, v[15], ans, ee, ans2;

void BT(int x) {
	if(x >= n) {
		ans2 = max(ans, ans2);
		return;
	}
	for(int i = ee; i >= 0; i--) {
		ans += i * v[x];
		int tmp = ee;
		ee -= i;
		ee = ee + r;
		if(ee > e) ee = e;
		BT(x + 1);
		ee = tmp;
		ans -= i * v[x];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		cin >> e >> r >> n;
		for(int j = 0; j < n; ++j)
			cin >> v[j];
		ans2 = 0;
		ans = 0;
		ee = e;
		BT(0);	
		cout << "Case #" << i << ": " << ans2 << endl;
	}
	return 0;
}
