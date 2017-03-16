#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cassert>

#define ONE 1
#define I 2
#define J 3
#define K 4

#define MAXL 10001

using namespace std;

int mult(int x, int y) {
	static int mult_res[4][4] = {
		{ONE, I, J, K},
		{I, -ONE, K, -J},
		{J, -K, -ONE, I},
		{K, J, -I, -ONE}};

	int abs_res = mult_res[abs(x)-1][abs(y)-1];
	if (x*y < 0) {
		abs_res *= -1;
	}
	return abs_res;
}

int inv(int x) {
	if ((x == ONE) || (x == -ONE)) {
		return x;
	}
	return -x;
}


int main() {
	//freopen("in", "r", stdin);
	int t, T;

	cin >> T;

	int pre_res[MAXL];
	int suf_res[MAXL];

	string res;

	for (t = 0; t < T; ++t) {
		unsigned long long L, X;
		cin >> L >> X;
		string s;
		cin >> s;

		vector<int> in;
		for (size_t i = 0; i < s.size(); ++i) {
			switch (s[i]) {
			case 'i':
				in.push_back(I);
				break;
			case 'j':
				in.push_back(J);
				break;
			case 'k':
				in.push_back(K);
				break;
			}
		}

		pre_res[0] = suf_res[0] = 1;
		for (int i = 1; i <= L; ++i) {
			pre_res[i] = mult(pre_res[i-1], in[i-1]);
			suf_res[i] = mult(in[L-i], suf_res[i-1]);
		}

		assert(pre_res[L] == suf_res[L]);

		int mod_res[4] = 
			{1, pre_res[L], mult(pre_res[L], pre_res[L]), mult(mult(pre_res[L], pre_res[L]), pre_res[L])};

		assert((mod_res[2] == -ONE) || (mod_res[2] == ONE));

		vector<pair<int, int> > legal_first, legal_second;

		for (int m = 0; m < min(4ULL, X); ++m) {
			for (int i = 0; i < L; ++i) {
				int first_res = mult(mod_res[m], pre_res[i]);
				if (first_res == I) {
					// good!. Save remainder
					legal_first.push_back(make_pair(m, i));
				}

				int second_res = mult(suf_res[i], mod_res[m]);
				if (second_res == K) {
					legal_second.push_back(make_pair(m, i));
				}
			}
		}

		for (size_t i = 0; i < legal_first.size(); ++i) {
			for (size_t j = 0; j < legal_second.size(); ++j) {
				if (legal_first[i].first + legal_second[j].first < X) {
					if ((X-1) == (legal_first[i].first + legal_second[j].first)) {
						if ((legal_first[i].second+legal_second[j].second) >= L) {
							continue;
						}
					}
					int mod = (X-legal_first[i].first-legal_second[j].first)%4;
					int remainder = mult(mult(inv(pre_res[legal_first[i].second]), mod_res[mod]), inv(suf_res[legal_second[j].second]));
					if (remainder == J) {			
						goto found;
					}
				}
			}
		}

		res = "NO";
		goto notfound;
found:
		res = "YES";
notfound:

		cout << "Case #" << (t+1) << ": " << res << endl;
	}

	return 0;
}