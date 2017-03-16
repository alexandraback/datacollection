#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solve(vector<vector<int> >& data) {
	int n = data.size() / 2 + 1;
	map<int, int> m;
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			m[data[i][j]]++;
		}
	}
	vector<int> ans;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second & 1) {
			ans.push_back(it->first);
		}
	}
	if (ans.size() == n) {
		sort(ans.begin(), ans.end());
		return ans;
	} else {
		return vector<int>(n, -1);
	}
}

int main() {
	int T; cin >> T;
	for (int No = 1; No <= T; No++) {
		int N; cin >> N;
		vector<vector<int> > data(N*2-1, vector<int>(N));
		for (int i = 0; i < N*2-1; i++) {
			for (int j = 0; j < N; j++) {
				cin >> data[i][j];
			}
		}
		sort(data.begin(), data.end());
		vector<int> ans = solve(data);
		cout << "Case #" << No << ":";
		for (int i = 0; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}
