#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void single_test() {
	int b;
	ll m;
	cin >> b >> m;
	vector<string> res(b, string(b, '0'));
	for(int i=1; i<b; ++i) {
		for(int j=i+1; j<b; ++j) {
			res[i][j] = '1';
		}
	}
	vector<ll> c(b, 0LL);
	c[b-1] = 1LL;
	c[b-2] = 1LL;
	for(int i=b-3; i>0; --i) {
		c[i] = 2LL * c[i+1];
	}
	for(int i=1; i<b; ++i) {
		if(m>=c[i]) {
			res[0][i] = '1';
			m -= c[i];
		}
	}
	if(m!=0LL) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;
	for(int i=0; i<b; ++i) {
		cout << res[i] << endl;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		single_test();
	}
	return 0;
}
