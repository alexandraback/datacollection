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

int tens[4] = {1, 10, 100, 1000};

string myToString(int len, int n) {
	string str = to_string(n);
	int d = len - (int)str.size();
	while (d--) {
		str = "0" + str;
	}
	return str;
}

bool myMatch(string str, string ptn) {
	for (int i = 0; i < str.size(); i++) {
		if (ptn[i] != '?' && ptn[i] != str[i]) {
			return false;
		}
	}
	return true;
}


int main() {
	FILE* stream;
	freopen_s(&stream, "B-small-attempt1.in", "r", stdin);
	freopen_s(&stream, "B-small-attempt1.out", "w", stdout);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		string str1, str2;
		cin >> str1 >> str2;
		int len = str1.size();
		int lmt = tens[len];
		int dist = INF;
		string ans1, ans2;
		for (int i = 0; i < lmt; i++) {
			string tmp1 = myToString(len, i);
			if (myMatch(tmp1, str1) == false) continue;
			for (int j = max(0, i-dist); j < min(lmt, i+dist+1); j++) {
				int tmpDis = abs(i - j);
				if (tmpDis >= dist) continue;
				string tmp2 = myToString(len, j);
				if (myMatch(tmp2, str2) == false) continue;
				if (tmpDis < dist) {
					ans1 = tmp1;
					ans2 = tmp2;
					dist = tmpDis;
				}
			}
		}

		cout << "Case #" << cas << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}