#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> getResult(unordered_map<int, int>&record, int N) {
	vector<int> ret;
	for (auto it = record.begin(); it!= record.end(); it++) {
		if ((it->second) % 2 != 0) ret.push_back(it->first);
	}
	if (ret.size() != N) {
		cout << "something bad happes" << endl;
	}
	sort(ret.begin(), ret.end());
	return ret;
}
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i<cases; i++) {
		int N;
		cin >> N;
		unordered_map<int, int> record;
		for (int j = 0; j<(2*N-1)*N; j++) {
			int tmp;
			cin >> tmp;
			record[tmp] += 1;
		}
		auto ret = getResult(record, N);
		cout << "Case #" << i+1 << ":";
		for (int j = 0; j< ret.size(); j++) {
			cout << " " << ret[j];
		}
		cout << endl;
	}
}