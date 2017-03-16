#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int k, n;
		cin >> k >> n;

		vector<int> need_key(n), alr_have(k);
		for (int i = 0; i < k; i++) {
			cin >> alr_have[i];
			alr_have[i]--;
		}

		vector< vector<int> > new_key(n);
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> need_key[i] >> tmp; need_key[i]--;
			new_key[i].resize(tmp);
			for (int j = 0; j < tmp; j++) {
				cin >> new_key[i][j];
				new_key[i][j]--;
			}
		}

		vector< pair<bool, vector<int> > > data(1 << n);
		vector< pair<int, int> > last(1 << n);
		data[0] = make_pair(true, vector<int>(200));
		last[0] = make_pair(-1, -1);
		for (int i = 0; i < alr_have.size(); i++)
			data[0].second[alr_have[i]]++;

		queue<int> qu;
		qu.push(0);

		while (!qu.empty()) {
			int i = qu.front(); qu.pop();
			for (int j = 0; j < n; j++) {
				int tmp = i | (1 << j);
				if (tmp != i && data[i].second[need_key[j]] > 0 && !data[tmp].first) {
					data[tmp] = make_pair(true, data[i].second);
					data[tmp].second[need_key[j]]--;
					for (int w = 0; w < new_key[j].size(); w++)
						data[tmp].second[new_key[j][w]]++;
					last[tmp] = make_pair(i, j);
					qu.push(tmp);
				}
			}
		}

		cout << "Case #" << q + 1 << ": ";
		if (data.back().first) {
			vector<int> res;
			for (int i = (1 << n) - 1; i != 0; i = last[i].first)
				res.push_back(last[i].second);
			for (auto it = res.rbegin(); it != res.rend(); it++)
				cout << *it + 1 << " ";
		} else
			cout << "IMPOSSIBLE";
		cout << endl;
	}
}