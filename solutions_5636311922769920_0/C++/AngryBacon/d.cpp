#include <iostream>
using namespace std;

long long k, c, s;

void solve()
{
	cin >> k >> c >> s;
	if (s * c < k) {
		puts("IMPOSSIBLE");
		return;
	}
	long long tot = 0;
	long long pre = -1;
	for(int i = 0; i < s; ++ i) {
		long long cur = tot;
		tot = min(tot + 1, k - 1);
		for(int j = 1; j < c; ++ j) {
			cur = cur * k + tot;
			tot = min(tot + 1, k - 1);
		}
		if (cur == pre) break;
		if (i) cout << ' ';
		cout << cur + 1;
		pre = cur;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++ i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
