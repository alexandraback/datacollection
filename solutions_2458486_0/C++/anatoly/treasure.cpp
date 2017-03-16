#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


bool opened[200];
vector<int> solution;

bool solve(multiset<int>& keys, const vector<int>& keyTypes, const vector<vector<int>>& chests);

bool try_open(int chestIndex, multiset<int>& keys, const vector<int>& keyTypes, const vector<vector<int>>& chests) {
	cout << "try_open: " << chestIndex << endl;
	int kt = keyTypes[chestIndex];
	auto keyIt = keys.find(kt);
	if (keyIt != keys.end()) {
		keys.erase(keyIt);
		opened[chestIndex] = true;
		solution.push_back(chestIndex);

		for (int item = 0; item < chests[chestIndex].size(); ++item) {
			keys.insert(chests[chestIndex][item]);
		}

		if (solve(keys, keyTypes, chests))
			return true;

		solution.pop_back();
		opened[chestIndex] = false;

		for (int item = 0; item < chests[chestIndex].size(); ++item) {
			keys.erase(keys.find(chests[chestIndex][item]));
		}
		keys.insert(kt);
	}
	return false;
}

vector<vector<int>> gr;

bool is_reachable(const multiset<int>& keys,
				  const vector<int>& keyTypes, 
				  int v, 
				  vector<char>& visited) {
	if (visited[v])
		return false;

	visited[v] = true;
	if (keys.find(keyTypes[v]) != keys.end())
		return true;

	for (int w : gr[v]) {
		if (is_reachable(keys, keyTypes, w, visited))
			return true;
	}

	return false;
}

void build_gr(vector<int>& keyTypes, vector<vector<int>>& chests) {
	gr.clear(); 
	gr.resize(keyTypes.size() + 1);
	
	for (int v = 0; v < chests.size(); ++v) {
		for (int kt : chests[v]) {
			for (int w = 0; w < chests.size(); ++w) {
				if (v != w && keyTypes[w] == kt) {
					gr[w].push_back(v);
				}
			}
		}
	}
}

bool is_valid(multiset<int>& keys, const vector<int>& keyTypes, const vector<vector<int>>& chests) {
	vector<int> keyUsers(1000);
	vector<int> keyCounts(1000);

	for (int i = 0; i < keyTypes.size(); ++i) {
		if (opened[i]) continue;

		keyUsers[keyTypes[i] - 1]++;

		for (int kt : chests[i]) {
			keyCounts[kt - 1]++;
		}
	}

	for (auto kt : keys) {
		keyCounts[kt - 1]++;
	}

	for (int i = 0; i < keyUsers.size(); ++i) {
		if (keyUsers[i] > keyCounts[i])
			return false;
	}

	for (int i = 0; i < keyTypes.size(); ++i) {
		vector<char> visited(gr.size());
		if (!opened[i] && !is_reachable(keys, keyTypes, i, visited))
			return false;
	}

	return true;
}

bool solve(multiset<int>& keys, const vector<int>& keyTypes, const vector<vector<int>>& chests) {
	if (!is_valid(keys, keyTypes, chests)) {
		//cout << "not valid" << endl;
		return false;
	}
	// FIXME: keep'em sorted
	/*for (int k : keys) {
		int count = 0;
		int chestIndex = -1;
		for (int i = 0; i < keyTypes.size(); ++i) {
			if (!opened[i] && keyTypes[i] == k) {
				++count;
				chestIndex = i;
			}
		}
		if (count == 1)
			return try_open(chestIndex, keys, keyTypes, chests);
	}*/

	bool complete = true;
	for (int i = 0; i < keyTypes.size(); ++i) {
		if (opened[i])
			continue;

		complete = false;
		int kt = keyTypes[i];
		auto keyIt = keys.find(kt);
		if (keyIt != keys.end()) {
			keys.erase(keyIt);
			opened[i] = true;
			solution.push_back(i);

			for (int item = 0; item < chests[i].size(); ++item) {
				keys.insert(chests[i][item]);
			}

			if (solve(keys, keyTypes, chests))
				return true;

			solution.pop_back();
			opened[i] = false;

			for (int item = 0; item < chests[i].size(); ++item) {
				keys.erase(keys.find(chests[i][item]));
			}
			keys.insert(kt);
		}
	}
	return complete;
}


int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int K, N;
		cin >> K >> N;
		multiset<int> keys;

		for (int i = 0; i < K; ++i) {
			int key; cin >> key;
			keys.insert(key);
		}

		vector<int> keyTypes(N);
		vector<vector<int> > chests(N);

		for (int chest = 0; chest < N; ++chest) {
			int keyCount; 
			cin >> keyTypes[chest] >> keyCount;

			chests[chest].resize(keyCount);
			for (int i = 0; i < keyCount; ++i)
				cin >> chests[chest][i];
		}

		cout << "Case #" << tc + 1 << ": ";
		build_gr(keyTypes, chests);
		fill_n(opened, 200, false);
		solution.clear();
		if (solve(keys, keyTypes, chests)) {
			for (int i = 0; i < solution.size(); ++i)
				cout << solution[i] + 1 << (i + 1 < solution.size() ? " " : "");
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << endl;
	}
}