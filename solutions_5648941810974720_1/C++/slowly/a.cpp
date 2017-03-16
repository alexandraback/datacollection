#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

string getResults(string &str) {
	unordered_map<char, int> record;
	for (int i = 0; i<str.size(); i++) {
		record[str[i]] += 1;
	}
	vector<int> results;
	if (record['Z'] > 0) {
		int count = record['Z'];
		for (int i = 0; i < count; i++) results.push_back(0);
		record['Z'] -= count;
		record['E'] -= count;
		record['R'] -= count;
		record['O'] -= count;
	}

	if (record['W'] > 0) {
		int count = record['W'];
		for (int i = 0; i<count; i++) results.push_back(2);
		record['T'] -= count;
		record['W'] -= count;
		record['O'] -= count;
	}

	if (record['X'] > 0) {
		int count = record['X'];
		for (int i = 0; i< count; i++) results.push_back(6);
		record['S'] -= count;
		record['I'] -= count;
		record['X'] -= count;
	}

	if (record['G'] > 0) {
		int count = record['G'];
		for (int i = 0; i<count; i++) results.push_back(8);
		record['E'] -= count;
		record['I'] -= count;
		record['G'] -= count;
		record['H'] -= count;
		record['T'] -= count;
	}

	if (record['S'] > 0) {
		int count = record['S'];
		for (int i = 0; i<count; i++) results.push_back(7);
		record['S'] -= count;
		record['E'] -= 2*count;
		record['V'] -= count;
		record['N'] -= count;
	}
	
	if (record['V'] > 0) {
		int count = record['V'];
		for (int i = 0; i<count; i++) results.push_back(5);
		record['F'] -= count;
		record['I'] -= count;
		record['V'] -= count;
		record['E'] -= count;
	}

	if (record['T'] > 0) {
		int count = record['T'];
		for (int i = 0; i<count; i++) results.push_back(3);
		record['T'] -= count;
		record['H'] -= count;
		record['R'] -= count;
		record['E'] -= 2*count;
	}

	if (record['F'] > 0) {
		int count = record['F'];
		for (int i = 0; i<count; i++) results.push_back(4);
		record['F'] -= count;
		record['O'] -= count;
		record['U'] -= count;
		record['R'] -= count;
	}
	
	if (record['O'] > 0) {
		int count = record['O'];
		for (int i = 0; i<count; i++) results.push_back(1);
		record['O'] -= count;
		record['N'] -= count;
		record['E'] -= count;
	}
	if (record['I'] > 0) {
		int count = record['I'];
		for (int i = 0; i<count; i++) results.push_back(9);
	}
	sort(results.begin(), results.end());
	string ret = "";
	for (int i = 0; i<results.size(); i++) {
		ret = ret + to_string(results[i]);
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i<cases; i++) {
		string tmp;
		cin >> tmp;
		cout << "Case #" << i+1 << ": " << getResults(tmp) << endl;
	}
}
