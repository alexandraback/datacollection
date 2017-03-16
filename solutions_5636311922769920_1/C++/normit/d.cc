#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

void solve()
{
	ll k,c,s;
	cin >> k >> c >> s;
	if (s * c < k) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	ll x = 0;
	bool done = false;
	while(!done) {
		ll y = 0;
		for(int i = 0; i < c; ++i) {
			y = y * k + x;
			x = x + 1;
			if (x >= k) {x = k-1; done=true; }
		}
		cout << y + 1 << " ";
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}