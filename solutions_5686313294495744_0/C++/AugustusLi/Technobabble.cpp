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

const int N = 16;
const double eps = 0.00001;
const int INF = 0x3fffffff;

string first[N];
string second[N];

bool judge(int n, int mask) {
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if ((mask&(1 << i)) == 0) {
			bool f1 = false;
			bool f2 = false;
			for (int j = 0; j < n; j++) {
				if ((mask&(1 << j)) != 0) {
					if (first[i] == first[j]) f1 = true;
					if (second[i] == second[j]) f2 = true;
				}
			}
			if (f1 == false || f2 == false) {
				return false;
			}
		}
	}
	return true;
}

int countOne(int x) {
	int cnt = 0;
	while (x) {
		cnt++;
		x = x&(x - 1);
	}
	return cnt;
}

int main() {
	FILE* stream;
	freopen_s(&stream, "C-small-attempt0.in", "r", stdin);
	freopen_s(&stream, "C-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> first[i];
			cin >> second[i];
		}

		int bitNum = 1 << n;

		int ans = 0;

		for (int mask = 0; mask < bitNum; mask++) {
			if (judge(n, mask)) {
				int tmp = countOne(mask);
				ans = max(n-tmp, ans);
			}
		}

		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}