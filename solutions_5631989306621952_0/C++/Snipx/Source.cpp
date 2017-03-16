#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>
#include <memory.h>
#include <sstream>
#include<array>

using namespace std;

string get(string s) {
	if (s == "") {
		return s;
	}
	bool allLettersSame = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[0]) {
			allLettersSame = false;
		}
	}
	if (allLettersSame) {
		return s;
	}
	else {
		int mx = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] > s[mx]) {
				mx = i;
			}
		}
		string res = get(s.substr(0, mx));
		int cnt = 0;
		for (int i = mx; i < s.length(); i++) {
			if (s[i] == s[mx]) {
				cnt++;
			} else {
				res += s[i];
			}
		}
		string t = "";
		for (int j = 0; j < cnt; j++) {
			t += s[mx];
		}
		return t + res;
	}
}


int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int t = 1; t <= tests; t++) {
		string s;
		cin >> s;
		cout << "Case #" << t << ": " << get(s) << endl;
	}
	

	//system("pause");
	return 0;
}
