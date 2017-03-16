//
//  main.cpp
//  GoogleCodeJam
//
//  Created by Jing Shan on 4/15/16.
//  Copyright © 2016 Jing Shan. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution {
private:

public:
	vector<int> missingLine (vector<vector<int> > &input) {
		vector<int> ans;
		if (input.empty() || input[0].empty()) return ans;
		unordered_map<int, int> map;
		int m = (int)input.size();
		int n = (int)input[0].size();
		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < n; ++c) {
				map[input[r][c]]++;
			}
		}
		
		for (auto &kv : map){
			if (kv.second % 2 == 1) {
				ans.push_back(kv.first);
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};


int main(int argc, const char * argv[]) {
	Solution sol;
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >>  N;
		vector<vector<int> > input(2*N-1, vector<int>(N, 0));
		for (int j = 0; j < 2*N-1; ++j) {
			for (int k = 0; k < N; ++k) {
				int num;
				cin >> num;
				input[j][k] = num;
			}
		}
		vector<int> missing = sol.missingLine(input);
		cout << "Case #" << i+1 << ":";
		for (int l = 0; l < N; ++l) {
			cout << " " << missing[l];
		}
		cout << endl;
	}
}
