#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;

int main() {
	int kase; 
	cin >> kase;
	for (int ii = 1; ii <= kase; ii++) {

		cin >> n;
		vector<vector<int> > a;
		for (int i = 0; i < 2 * n - 1; i++) {
			vector<int> b(n);
			for (int j = 0; j < n; j++) {
				cin >> b[j];
			}
			a.push_back(b);
		}
		map<int, int> occur;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < n; j++) {
				occur[a[i][j]]++;
			}
		}
		vector<int> ans;
		for (auto &pair : occur) {
			if (pair.second % 2){
				ans.push_back(pair.first);
			}
		}
		sort(ans.begin() ,ans.end());
		cout << "Case #" << ii << ":";
		for (int i = 0; i < n; i++) {
			cout << ' ' << ans[i];
		}
		cout<< endl;
	}
	return 0;
}