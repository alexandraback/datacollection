#include <cstdio>
#include <iostream>

using namespace std;


void solve()
{
	string buf;

	cin >> buf;
	int n = buf.length();

	int cnt = 0;

	for(int i = 1; i < n; ++i) {
		if (buf[i] != buf[i-1]) {
			cnt += 1;
		}
	}
	if (buf[n-1] == '-') {
		cnt += 1;
	}

	cout << cnt << endl;

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