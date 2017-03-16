#include <bits/stdc++.h>
using namespace std;

#define MAXH 2503
int N;
bool present[MAXH];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("rankfile.in", "r", stdin);
	freopen("rankfile.out", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		cin >> N;
		memset(present, false, sizeof present);
		for (int i = 0; i < 2 * N - 1; i++) {
			for (int j = 0; j < N; j++) {
				int x;
				cin >> x;
				present[x] = !present[x];
			}
		}
		vector<int> ans;
		for (int i = 0; i < MAXH; i++) {
			if (present[i]) {
				ans.push_back(i);
			}
		}
		if (ans.size() != N) throw domain_error("bad algorithm");
		for (int i = 0; i < N; i++) {
			cout << ans[i];
			if (i != N - 1) {
				cout << ' ';
			}
		}
		cout << '\n';
	}

	cout.flush();
	return 0;
}
