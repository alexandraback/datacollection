#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using quaternion = signed char; // 1,i,j,k == 1,2,3,4

quaternion chr_to_quater(char c) {
	switch (c) {
	case 'i': return 2;
	case 'j': return 3;
	case 'k': return 4;
	default: return 0;
	}
}

quaternion quater_mul(quaternion a, quaternion b) {
	static const vector<vector<quaternion>> table
	{ { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
	static auto sgn = [] (quaternion x) {return (x > 0) ? 1 : -1; };
	static auto abs = [] (quaternion x) {return (x > 0) ? x : -x; };
	return sgn(a) * sgn(b) * table[abs(a)-1][abs(b)-1];
}

quaternion quater_pow(quaternion a, int b) {
	quaternion result = 1;
	for (int i = 0; i < b % 4; i++) {
		result = quater_mul(result, a);
	}
	return result;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		int L, X;
		string s;
		in >> L >> X >> s;
		quaternion block_prod = accumulate(s.begin(), s.end(), 1,
			[] (quaternion q, char c) {return quater_mul(q, chr_to_quater(c)); });
		quaternion full_prod = quater_pow(block_prod, X);

		int p1 = 0;
		for (quaternion prod = chr_to_quater(s[0]); prod != 2 && p1 < min(4, X)*L;
			p1++, prod = quater_mul(prod, chr_to_quater(s[p1%L])));
		int p2 = 0;
		for (quaternion prod = chr_to_quater(s[L - 1]); prod != 4 && p2 < min(4, X)*L;
			p2++, prod = quater_mul(chr_to_quater(s[L - 1 - p2%L]), prod));

		out << "Case #" << test << ": " <<
		((full_prod == -1 && p1 < min(4, X)*L && p2 < min(4, X)*L && p1 + p2 + 2 < X*L) ? "YES" : "NO") << endl;
	}
	return 0;
}