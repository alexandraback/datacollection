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

using namespace std;

class Solution {
private:

public:
	string lastWord(string &s) {
		string ans;
		if (s.empty()) return ans;
		for (const char &c : s) {
			if (ans.empty()) {
				ans += c;
			}
			else if (c >= ans[0]) {
				ans = c + ans;
			}
			else {
				ans += c;
			}
		}
		return ans;
	}
};


int main(int argc, const char * argv[]) {
	Solution sol;
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string S;
		cin >>  S;
		string word = sol.lastWord(S);
		cout << "Case #" << i+1 << ": " << word << endl;
	}
}
