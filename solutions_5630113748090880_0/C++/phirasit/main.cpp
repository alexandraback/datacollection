#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void solve(int);

int main() {
	int t;
	cin >> t;
	for(int case_id = 1;case_id <= t;case_id++) {
		solve(case_id);
	}
	return 0;
}

vector<int> ans;
map<int, int> data;
int n;

void solve(int case_id) {
	cin >> n;
	data.clear();
	ans.clear();
	for(int i = 0;i < 2*n-1;i++) {
		for(int j = 0;j < n;j++) {
			int val;
			cin >> val;
			data[val]++;
		}
	}

	for(auto it : data) {
		if(it.second % 2) {
			ans.push_back(it.first);
		}
	}

	cout << "Case #" << case_id << ": ";
	for(auto val : ans) {
		cout << val << " ";
	}
	cout << endl;
	
	cerr << case_id << endl;
}