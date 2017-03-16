#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void
solve()
{
	long long k, c, s;
	cin >> k >> c >> s;
	if (c * s < k) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}
	for (int i = 0; i < k; i += c) {
		long long cur = i;
		for (int j = 1; j < c; ++j) {
			cur *= k;
			cur += (i + j) % k;
		}
		cout << " " << cur + 1;
	}
	cout << endl;
}

int
main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d:", i + 1);
        solve();
    }
}
