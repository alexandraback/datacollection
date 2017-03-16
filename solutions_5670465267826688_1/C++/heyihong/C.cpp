#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const char ch[4] = {'1', 'i', 'j', 'k'};

//1 = 0, i = 1, j = 2, k = 3, -1 = 4, -i = 5, -j = 6, -k = 7

const int _trans[4][4] = {
	{0, 1, 2, 3},
	{1, 4, 3, 6},
	{2, 7, 4, 1},
	{3, 2, 5, 4}
};

int trans[8][8];

struct State {
	State() {
		memset(bo, false, sizeof(bo));
	}
	bool bo[8 * 8 * 8];

	bool get(int a, int b, int c) {
		return bo[c * 64 + b * 8 + a];
	}

	void set(int a, int b, int c, bool _bo) {
		bo[c * 64 + b * 8 + a] = _bo;
	}
};

int transfer(int *a, int l, int r) {
	int st = a[l];
	for (int i= l + 1; i <= r; ++i)
		st = trans[st][a[i]];
	return st;
}

State operator * (const State & s1, const State & s2) {
	State res;
	for (int i = 0; i != 512; ++i)
		if (s1.bo[i]) {
			for (int j = 0; j != 512; ++j) 
				if (s2.bo[j]) {
					int tmp[6];
					for (int k = 0; k != 3; ++k)
						tmp[k] = (i >> (k * 3)) & 7;
					for (int k = 0; k != 3; ++k)
						tmp[k + 3] = (j >> (k * 3)) & 7;
					for (int a = 0; a != 4; ++a)
						for (int b = a + 1; b != 5; ++b) {
							int x1 = transfer(tmp, 0, a);
							int x2 = transfer(tmp, a + 1, b);
							int x3 = transfer(tmp, b + 1, 5);
							res.set(x1, x2, x3, true);
						}
				}
		}
	return res;
}

int number(char c) {
	for (int i = 0; i != 4; ++i)
		if (ch[i] == c)
			return i;
	return -1;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 0; i != 8; ++i)
		for (int j  = 0; j != 8; ++j) {
			int add = (i / 4 + j / 4) % 2 * 4;
			trans[i][j] = (_trans[i % 4][j % 4] + add) % 8;
		}
	int test_case, x;
	long long l;
	string s;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; ++tc) {
		cin >> x >> l >> s;
		bool f[4][8][8][8], _f[4][8][8][8];
		memset(f, false, sizeof(f));
		f[0][0][0][0] = true;
		for (int i = 0; i != s.size(); ++i) {
			int num = number(s[i]);
			memset(_f, false, sizeof(_f));
			for (int a = 0; a <= 3; ++a)
				for (int b = 0; b < 8; ++b)
					for (int c = 0; c < 8; ++c)
						for (int d = 0; d < 8; ++d)
							if (f[a][b][c][d]) {
								if (a <= 1) //0 1
									_f[1][trans[b][num]][c][d] = true;
								if (a != 3) //0 1 2
									_f[2][b][trans[c][num]][d] = true;
								if (a != 1) //0 2 3
									_f[3][b][c][trans[d][num]] = true;
							}
			memcpy(f, _f, sizeof(_f));
		}
		State state, p_state;
		state.set(0, 0, 0, true);
		for (int b = 0; b < 8; ++b)
			for (int c = 0; c < 8; ++c)
				for (int d = 0; d < 8; ++d)
					p_state.set(b, c, d, f[3][b][c][d]);
		for (; l >= 1; l /= 2) {
			if (l & 1) 
				state = state * p_state;
			p_state = p_state * p_state;
		}
		cout << "Case #" << tc << ": " << (state.get(1, 2, 3) ? "YES" : "NO") << endl;
	}	
	return 0;
}
