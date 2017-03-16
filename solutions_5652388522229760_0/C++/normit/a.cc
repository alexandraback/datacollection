#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

void solve()
{
	ll n;
	cin >> n;

	int check[10] = {0, };
	int cnt = 0;

	for(int i = 1; i <= 1000; ++i) {
		ll x = n * i;
		//cout << x << endl;
		while (x) {
			int y = x % 10;
			if (check[y] == 0) {
				check[y] = 1;
				++cnt;
			}
			x /= 10;
		}
		if (cnt == 10) {
			cout << n * i << endl;
			return;
		}
	}

	cout << "INSOMNIA" << endl;
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