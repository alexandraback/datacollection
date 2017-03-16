#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int ans = 0;

void go(int k, const vector<int> &a, int i, int n)
{
	if (n >= a.size()) return;
	if (i >= a.size()) {
		ans = min(n, ans);
		return;
	}
	if (k > a[i]) {
		go(k + a[i], a, i + 1, n);
	} else {
		go(k + k - 1, a, i, n + 1);
		go(k, a, i + 1, n + 1);
	}
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		int a, n;
		cin >> a >> n;
		vector<int> m(n);
		for (int i = 0; i < n; i++) cin >> m[i];
		sort(m.begin(), m.end());
		ans = n;
		go(a, m, 0, 0);
		cout << "Case #" << ti << ": " << ans << endl;
	}

	return 0;
}
