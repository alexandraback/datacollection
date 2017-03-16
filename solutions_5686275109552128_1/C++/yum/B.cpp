#include <bits/stdc++.h>
using namespace std;

int tryrd(vector<int> const& st, int h) {
	int ans = 0;
	for (int x : st) if (x>h) ans += (x+h-1)/h-1;
	return ans;
}

int main() {
	int TC, D;
	cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		vector<int> st;
		cin >> D;
		int maxh = 0;
		for (int d = 0,x; d<D; d++) {
			cin >> x;
			maxh = max(maxh, x);
			st.push_back(x);
		}
		int ans = INT_MAX;
		for (int h = 1; h <= maxh; h++) {
			ans = min(ans, tryrd(st, h)+h);
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}
