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

const int N = 35;
const double eps = 0.00001;
const int INF = 0x3fffffff;


int bits[N];
unsigned int ans[12];

bool check(string str, int base, int div) {
	int r = 0;
	int multi = 1;
	for (int i = 0; i < str.length(); i++, multi = multi*base%div) {
		if (str[i] == '1') {
			r = (r + multi) % div;
		}
	}
	if (r == 0) return true;
	else return false;
}

unsigned int getSum(unsigned int a, int n) {
	unsigned int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = ret*a+1;
	}
	return ret;
}

void search(int len, int n, int lvl, int& cnt) {
	if (cnt == 0) return;
	if (lvl == n) {
		for (int i = len - 1; i >= 0; i--) {
			cout << bits[i];
		}
		for (int i = 2; i <= 10; i++) {
			cout << " " << ans[i];
		}
		cout << endl;
		cnt--;
		return;
	}

	if ((len-1)%n != lvl) {
		for (int idx = lvl; idx < len-1; idx += n) {
			bits[idx] = 1;
			search(len, n, lvl + 1, cnt);
			bits[idx] = 0;
		}
	}
	else {
		search(len, n, lvl + 1, cnt);
	}
	return;
}


int main() {
	FILE* stream;
	freopen_s(&stream, "C-small-attempt1.in", "r", stdin);
	freopen_s(&stream, "C-small-attempt1.out", "w", stdout);
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		int len, cnt;
		cin >> len >> cnt;
		cout << "Case #" << cas << ":" << endl;
		for (int n = 2; n <= len; n++) {
			if ((len - 1) % n == 0) continue;
			memset(bits, 0, sizeof(bits));
			bits[0] = bits[len - 1] = 1;

			for (int i = 2; i <= 10; i++) {
				ans[i] = getSum(i, n);
			}
	
			search(len, n, 1, cnt);
		}
	}
	return 0;
}