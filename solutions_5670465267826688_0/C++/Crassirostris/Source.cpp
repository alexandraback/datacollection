#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

enum Quaternion {
	ONE,
	I,
	J,
	K,
	MONE,
	MI,
	MJ,
	MK
};

Quaternion mult_table[8][8] = {
	{ ONE, I, J, K, MONE, MI, MJ, MK },
	{ I, MONE, K, MJ, MI, ONE, MK, J },
	{ J, MK, MONE, I, MJ, K, ONE, MI },
	{ K, J, MI, MONE, MK, MJ, I, ONE },
	{ MONE, MI, MJ, MK, ONE, I, J, K },
	{ MI, ONE, MK, J, I, MONE, K, MJ },
	{ MJ, K, ONE, MI, J, MK, MONE, I },
	{ MK, MJ, I, ONE, K, J, MI, MONE }
};

string multiply_string(string &s, int count) {
	string result;
	for (int i = 0; i < count; ++i)
		result += s;
	return result;
}

Quaternion convert(char ch) {
	return ch == 'i' ? I : ch == 'j' ? J : K;
}

Quaternion operator *(Quaternion left, Quaternion right) {
	return mult_table[left][right];
}


int find_prefix(string &s, int offset, Quaternion to_find) {
	auto result = ONE;
	for (int i = offset; i < s.length(); ++i) {
		result = result * convert(s[i]);
		if (result == to_find)
			return i + 1;
	}
	return s.length();
}

Quaternion evaluate(string &s, int offset, int end_offset) {
	auto result = ONE;
	for (int i = offset; i < end_offset; ++i)
		result = result * convert(s[i]);
	return result;
}

Quaternion fast_pow(Quaternion x, int power) {
	auto result = ONE;
	while (power > 0)
	{
		if (power & 1)
			result = result * x;
		x = x * x;
		power >>= 1;
	}
	return result;
}

bool solve() {
	int l, x;
	cin >> l >> x;
	string s, s1;
	cin >> s;
	s1 = multiply_string(s, min(x, 8));
	x = max(0, x - 8);
	int p1 = find_prefix(s1, 0, I);
	int p2 = find_prefix(s1, p1, J);
	if (evaluate(s1, 0, p1) != I || evaluate(s1, p1, p2) != J)
		return false;
	if (p2 == s1.length() && x == 0)
		return false;
	return evaluate(s1, p2, s1.length()) * fast_pow(evaluate(s, 0, s.length()), x) == K;
}

int main() {
	FILE *f;
	freopen_s(&f, "in.txt", "rt", stdin);
	freopen_s(&f, "out.txt", "wt", stdout);

	int t;
	cin >> t;
	for (int test_num = 1; test_num <= t; ++test_num) {
		bool ans = solve();
		cout << "Case #" << test_num << ": " << (ans ? "YES" : "NO") << endl;
	}
}