#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool exist(int fid, unordered_set<int> &curr, unordered_map<int, vector<int>>&reverse) {
	for (int i = 0; i<reverse[fid].size(); i++) {
		if (curr.find(reverse[fid][i]) == curr.end()) return true;
	}
	return false;
}
int getLength(unordered_map<int, int>&record, int friends, int start, unordered_map<int, vector<int>>&reverse) {
	vector<int> list;
	unordered_set<int> curr;
	list.push_back(start);
	curr.insert(start);
	int c = start;
	for (;;) {
		int f = record[c];
		if (f == list[0]) return list.size();
		if (list.size() > 1 && f == list[list.size()-2]) {
			bool r = exist(c, curr, reverse);
			if (r) return curr.size() + 1;
			return curr.size();
		} 
		if (curr.find(f) != curr.end()) {
			if (reverse[start].size() == 0) return 1;
			if (reverse[start].size() == 1) return 2;
			if (reverse[start].size() > 1) return 3;
		}
		list.push_back(f);
		curr.insert(f);
		c = f; 
	}
}
int getResult(unordered_map<int, int> &record, int friends, unordered_map<int, vector<int>>&reverse) {
	int ret = 1;
	for (int i = 1; i<=friends; i++) {
		int length = getLength(record, friends, i, reverse);
		ret = max(ret, length);
	}
	return ret;
}
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i<cases; i++) {
		int friends;
		cin >> friends;
		unordered_map<int, int> record;
		unordered_map<int, vector<int>> reverse;
		for (int j = 0; j<friends; j++) {
			int fid ;
			cin >> fid;
			record[j+1] = fid;
			reverse[fid].push_back(j+1);
		}
		cout << "Case #" << i+1 << ": " << getResult(record, friends, reverse) << endl;
	}
}