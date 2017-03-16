/*/**/

#include <bits/stdc++.h>

using namespace std;

int num[2555];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		int n;
		cin >> n;
		memset(num, 0, sizeof num);
		for(int i = 0; i < 2 * n - 1; i++) {
			for(int j = 0; j < n; j++) {
				int foo;
				cin >> foo;
				num[foo] ^= 1;
			}
		}
		vector < int > ans;
		for(int i = 1; i < 2555; i++) {
			if(num[i]){
				ans.push_back(i);
			}
		}
		cout << "Case #" << tt << ":";
		for(int i = 0; i < n; i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}
