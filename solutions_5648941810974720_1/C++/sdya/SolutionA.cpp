#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

const string digs[10] = {
	"ZERO",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE"
};

string removedigit(string s, int dig, int* ret) {
	map<char, int> res;
	for (int i = 0; i < s.size(); ++i) {
		++res[s[i]];
	}

	int mn = 1000000;

	for (int i = 0; i < digs[dig].size(); ++i) {
		mn = min(mn, res[digs[dig][i]]);
	}

	*ret = mn;
	for (int i = 0; i < digs[dig].size(); ++i) {
		res[digs[dig][i]] -= mn;
	}

	string result = "";

	for (auto p : res) {
		for (int i = 0; i < p.second; ++i) {
			result += p.first;
		}
	}
	return result;
}

void solve(int tcase) {
	string s;
	cin >> s;

	vector<int> order = {2, 0, 6, 8, 4, 3, 1, 7, 5, 9};

	vector<int> cnt(10);

	for (int i = 0; i < order.size(); ++i) {
		s = removedigit(s, order[i], &cnt[order[i]]);
	}

	printf("Case #%d: ", tcase);
	for (int i = 0; i < cnt.size(); ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			printf("%d", i);
		}
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		solve(i + 1);
	}

	return 0;
}
