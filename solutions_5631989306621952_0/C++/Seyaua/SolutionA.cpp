#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdio>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

string solve(const string& s) {
	string front = "";
	string tail = "";

	char cur = 'A' - 1;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= cur) {
			front += s[i];
			cur = s[i];
		} else {
			tail += s[i];
		}
	}
	reverse(front.begin(), front.end());
	return front + tail;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		cout << "Case #" << i + 1 << ": " << solve(s) << endl;
	}

	return 0;
}