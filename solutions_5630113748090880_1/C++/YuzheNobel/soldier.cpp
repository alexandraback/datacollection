#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i <<":";
		int N;
		cin >> N;
		vector<int> row;
		unordered_map<int, int> stats;
		for (int j = 0; j < 2 * N - 1; j++) {
			for (int k = 0; k < N; k++) {
				int e;
				cin >> e;
				stats[e]++;
			}
		}
		for (auto iter = stats.begin(); iter != stats.end(); iter++)
			if (iter->second % 2)
				row.push_back(iter->first);
		sort(row.begin(), row.end());
		for (int n : row)
			cout << " " << n;
		cout << endl;
	}
	return 0;
}