#include <bits/stdc++.h>
using namespace std;

int tryrd(multiset<int> st, int h) {
	int ans = 0;
	for (;;) {
		auto it = --st.end();
		int x = *it;
		if (x <= h) return ans;
		ans++;
		st.erase(it);
		st.insert(h);
		st.insert(x-h);
	}
}

int main() {
	int TC, D;
	cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		multiset<int> st;
		cin >> D;
		int maxh = 0;
		for (int d = 0,x; d<D; d++) {
			cin >> x;
			maxh = max(maxh, x);
			st.insert(x);
		}
		int ans = INT_MAX;
		for (int h = 1; h <= maxh; h++) {
			ans = min(ans, tryrd(st, h)+h);
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}
