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

const int N = 1009;
const double eps = 0.00001;
const int INF = 0x3fffffff;




int main() {
	FILE* stream;
	freopen_s(&stream, "A-small-attempt0.in", "r", stdin);
	freopen_s(&stream, "A-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		string str;
		cin >> str;
		string ans = str.substr(0, 1);
		for (int i = 1; i < str.size(); i++) {
			if (str[i] >= ans[0]) {
				ans = str.substr(i, 1) + ans;
			}
			else {
				ans = ans + str.substr(i, 1);
			}
		}

		cout << "Case #" << cas << ": " << ans << endl;
		
	}
	return 0;
}