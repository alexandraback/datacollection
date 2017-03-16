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

const int N = 109;
const double eps = 0.00001;
const int INF = 0x3fffffff;


int main() {
	FILE* stream;
	freopen_s(&stream, "B-small-attempt0.in", "r", stdin);
	freopen_s(&stream, "B-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		string str;
		cin >> str;
		int n = str.length();
		for (int i = str.length() - 1; i >= 0; i--) {
			if (str[i] != '-') n--;
			else break;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) ans++;
			else if (str[i] != str[i - 1]) {
				ans++;
			}
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}