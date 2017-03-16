//a Hewr
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 110;

int a[MaxN];

int calc(int n, int ori) {
	int ret(0);
	for (int i = 1; i <= n; ++i) {
		while (ori <= a[i]) {
			if (ori <= 1) return 1000;
			ori += ori - 1;
			++ret;
		}
		ori += a[i];
	}
	return ret;
}

int main() {
	freopen("a.in", "r", stdin);
	int CA;
	cin >> CA;
	for (int Ca = 1; Ca <= CA; ++Ca) {
		int ori, n;
		cin >> ori >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1);
		int Ans = n;
		for (int i = 0; i < Ans; ++i) {
			int tmp = calc(n - i, ori) + i;
			Ans = min(Ans, tmp);
		}
		cout << "Case #" << Ca << ": " << Ans << endl;
	}
}
