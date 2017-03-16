#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

typedef __int64 I;

const int N = -1;
const double eps = 0.00001;
const int INF = 0x3fffffff;

string digitStrs[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int tbl[26];
vector<int> rslt;


int main() {
	FILE* stream;
	freopen_s(&stream, "A-large.in", "r", stdin);
	freopen_s(&stream, "A-large.out", "w", stdout);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		rslt.clear();
		memset(tbl, 0, sizeof(tbl));
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			tbl[str[i] - 'A']++;
		}

		int cnt = tbl['Z' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[0];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(0);
			}
		}

		cnt = tbl['W' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[2];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(2);
			}
		}

		cnt = tbl['X' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[6];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(6);
			}
		}

		cnt = tbl['S' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[7];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(7);
			}
		}

		cnt = tbl['V' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[5];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(5);
			}
		}

		cnt = tbl['G' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[8];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(8);
			}
		}

		cnt = tbl['F' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[4];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(4);
			}
		}

		cnt = tbl['O' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[1];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(1);
			}
		}

		cnt = tbl['T' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[3];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(3);
			}
		}

		cnt = tbl['I' - 'A'];
		if (cnt > 0) {
			string digitStr = digitStrs[9];
			for (int i = 0; i < digitStr.size(); i++) {
				tbl[digitStr[i] - 'A'] -= cnt;
			}
			for (int i = 0; i < cnt; i++) {
				rslt.push_back(9);
			}
		}

		sort(rslt.begin(), rslt.end());

		for (int i = 0; i < 26; i++) {
			if (tbl[i]) cout << "Error";
		}

		string ans = "";
		for (int i = 0; i < rslt.size(); i++) {
			ans += to_string(rslt[i]);
		}

		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}