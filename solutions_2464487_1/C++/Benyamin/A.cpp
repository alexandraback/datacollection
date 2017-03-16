// In The Name of God
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
typedef long long ll;

ifstream fin("A-large.in");
ofstream fout("A-large.out");
ll T, r, t, ans;

ll binary_search(ll st, ll ed) {
	ll mid = (st + ed) / 2;
	ll n = t;
	if(ed - st == 0) return st;
	if(ed - st == 1) {
		mid = ed;
		n += mid;
		n /= 2;
		n /= mid;
		n -= (mid + r);
		if(n < 0) return st;
		return ed;
	}	
	n += mid;
	n /= 2;
	n /= mid;
	n -= (mid + r);
	if(n < 0) return binary_search(st, mid - 1);
	return binary_search(mid, ed);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		cin >> r >> t;
		ans = binary_search(0, 1000 * 1000ll * 100 * 15);
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
