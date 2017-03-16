#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
void solutionB(vector<vector<int>> input, int number) {
	vector<int> result;
	unordered_map<int, int> hashmap;
	int n = input[0].size();
	for(int i = 0; i < 2 * n - 1; i++)
		for (int j = 0; j < n; j++) {
			if (hashmap.find(input[i][j]) == hashmap.end()) {
				hashmap.insert({ input[i][j] , 1 });
			}
			else
				hashmap[input[i][j]]++;
		}
	for (auto i : hashmap) {
		if (i.second % 2 != 0)
			result.push_back(i.first);
	}
	sort(result.begin(), result.end());
	//Case #1: 3 4 6
	cout << "Case #" << number << ":";
	for (int i = 0; i < result.size(); i++)
		cout << " " << result[i];
	cout << endl;
}
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<vector<int>> nums;
		for (int j = 0; j < 2 * n - 1; j++) {
			vector<int> line;
			nums.push_back(line);
			for (int k = 0; k < n; k++) {
				int tmp;
				cin >> tmp;
				nums[j].push_back(tmp);
			}
		}
		solutionB(nums, i + 1);
	}
	return 1;
}
