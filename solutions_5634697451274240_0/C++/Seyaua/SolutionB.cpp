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

int pancakes(const string& s) {
	int total = 0;
	for (int i = 0; i < s.length(); ++i) {
		int j = i;
		while (j < s.length() && s[i] == s[j]) {
			++j;
		}
		++total;
		i = j - 1;
	}

	if (s.back() == '+') {
		--total;
	}
	return total;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int result = pancakes(s);
		cout << "Case #" << i + 1 << ": " << result << endl;
	}

	return 0;
}