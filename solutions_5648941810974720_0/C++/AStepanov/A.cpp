#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;

void solve(){
	vector<string> a = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	string s;
	cin >> s;
	//vector<string> b = a;
	//random_shuffle(b.begin(), b.end());
	//for (int i = 0; i < 10; i++) s += b[i];

	char c[256] = { 0 };
	for (int i = 0; i < (int)s.length(); i++){
		c[s[i]]++;
	}
	vector<pair<int, char> > v = {

		{ 0, 'Z' },
		{ 2, 'W' },
		{ 6, 'X' },
		{ 8, 'G' },
		{ 4, 'U' },

		{ 5, 'F' },
		{ 7, 'V' },
		{ 3, 'H' },
		{ 1, 'O' },
		{ 9, 'E'}
	};
	vector<int> result;
	for (int i = 0; i < 10; i++){
		int digit = v[i].first;
		int cnt = c[v[i].second];
		for (int j = 0; j < a[digit].length(); j++){
			c[a[digit][j]] -= cnt;
		}
		for (int j = 0; j < cnt; j++) result.push_back(digit);
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++){
		cout << result[i];
	}
	cout << endl;
}

int main() {
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++){
		cout << "Case #" + to_string(test) + ": ";
		solve();
	}
	return 0;
}