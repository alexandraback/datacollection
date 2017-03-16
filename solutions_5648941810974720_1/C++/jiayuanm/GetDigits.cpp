#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

string s;
int table[30];

static const string D[] = {
	"ZERO",
	"TWO",
	"SIX",
	"FOUR",
	"FIVE",
	"THREE",
	"EIGHT",
	"SEVEN",
	"ONE",
	"NINE"
};

static const string DD = "ZWXUFRTVOI";
static const string DDD = "0264538719";

string solve() {
	memset(table, 0, sizeof(table));

	for (int i = 0; i < s.length(); ++i) {
		table[s[i] - 'A']++;
	}

	stringstream ss;
	for (int i = 0; i < 10; ++i) {
		if (table[DD[i] - 'A'] != 0) {
			int x = table[DD[i] - 'A'];
			ss << string(x, DDD[i]);
			for (auto &c : D[i]) {
				table[c - 'A'] -= x;
			}
			table[DD[i] - 'A'] = 0;
		}
	}
	string res = ss.str();
	sort(res.begin(), res.end());
	return res;
}


int main() {
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; ++tt) {
		cin >> s;
		cout << "Case #" << tt << ": " << solve() << endl;
	}
	return 0;
}