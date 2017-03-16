#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1, 2, 3, 4 -> 1, i, j, k

int xmul[5][5] = { {0, 0, 0, 0, 0}, 
             {0, 1, 2, 3, 4},
             {0, 2, -1, 4, -3},
             {0, 3, -4, -1, 2},
             {0, 4, 3, -2, -1} };

int mul(int x, int y) {
	if (x < 0) {
		return -mul(-x, y);
	}
	if (y < 0) {
		return -mul(x, -y);
	}

	return xmul[x][y];
}

int xpow(int x, long long p) {
	int powup = x;
	int ret = 1;
	for (int i = 0; i < 63; ++i) {
		if (p >> i & 1) {
			ret = mul(ret, powup);
		}
		powup = mul(powup, powup);
	}
	return ret;
}

int main() {
	int T;
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			cerr << mul(i, j) << " ";
		}
		cerr << endl;
	}

	cin >> T;

	for (int re = 1; re <= T; ++re) {
		long long n, x;
		string s, ans;
		vector<int> loop;
		cin >> n >> x >> s;
		for (int i = 0; i < n; ++i) {
			switch (s[i]) {
				case 'i': s[i] = 2; break;
				case 'j': s[i] = 3; break;
				case 'k': s[i] = 4; break;
			}
		}

		int loop_base = 1;
		for (int i = 0; i < n; ++i) {
			loop_base = mul(loop_base, s[i]);
		}
		cerr << loop_base << endl;

		int cur = loop_base;
		do {
			loop.push_back(cur);
			cur = mul(cur, loop_base);
		} while (cur != loop_base);

		if (xpow(loop_base, x) != -1) {
			ans = "NO";
		} else {
			// scan the first i
			cur = 1;
			long long first_i = -1;
			for (int i = 0; i < x && i < loop.size(); ++i) {
				for (int j = 0; j < s.length(); ++j) {
					cur = mul(cur, s[j]);
					if (cur == 2) {
						first_i = i * s.length() + j + 1;
						break;
					}
				}
				if (first_i >= 0) break;
			}
			// scan the last k
			cur = 1;
			long long last_k = -1;
			for (int i = 0; i < x && i < loop.size(); ++i) {
				for (int j = s.length() - 1; j >= 0; --j) {
					cur = mul(s[j], cur);
					if (cur == 4) {
						last_k = i * s.length() + s.length() - 1 - j + 1;
						break;
					}
				}
				if (last_k >= 0) break;
			}

			if (first_i >= 0 && last_k >= 0 && first_i + last_k < x * n) {
				ans = "YES";
			} else {
				ans = "NO";
			}
		}
		cout << "Case #" << re << ": " << ans << endl;
	}
	return 0;
}