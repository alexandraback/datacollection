#include <algorithm>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

struct Quaternion {
	int val;
	Quaternion(const char c) {
		switch (c) {
		case '1':
			val = 1;
			break;
		case 'i':
			val = 2;
			break;
		case 'j':
			val = 3;
			break;
		case 'k':
			val = 4;
			break;
		default:
			val = 0;
		}
	}

	bool operator==(const Quaternion &other) const {
		return val == other.val;
	}

	bool operator<(const Quaternion &other) const {
		return val < other.val;
	}

	const Quaternion operator*(const Quaternion& other) const {
		Quaternion res;

		const static vector<int> matrix = { 1,  2,  3,  4,
										   2, -1,  4, -3,
										   3, -4, -1,  2,
										   4,  3, -2,  -1 };

		int sign = 1;
		if (val < 0)
			sign *= -1;

		if (other.val < 0)
			sign *= -1;

		res.val = matrix[(abs(val) - 1) * 4 + abs(other.val) - 1];
		res.val *= sign;

		return res;
	}

	const Quaternion operator/(const Quaternion& other) const {
		Quaternion res;

		static vector<int> matrix(16, 0);

		int sign = 1;
		if (val < 0)
			sign *= -1;

		if (other.val < 0)
			sign *= -1;

		int pos = (abs(val) - 1) * 4 + abs(other.val) - 1;

		if (matrix[pos] == 0) {
			for (int i = -4; i <= 4; i++) {

				if (i != 0 && Quaternion(abs(other.val)) * Quaternion(i) == Quaternion(abs(val))) {
					matrix[pos] = i;
					break;
				}
			}
		}

		res.val = matrix[pos];
		res.val *= sign;

		return res;
	}

private:
	Quaternion() = default;
	Quaternion(int v) {
		val = v;
	}
};

bool solve(const string& str, long long x) {

	const Quaternion I{ 'i' };
	const Quaternion J{ 'j' };
	const Quaternion K{ 'k' };


	map<Quaternion, int> prefixes;
	map<Quaternion, int> suffixes;

	Quaternion L = '1';
	prefixes[L] = 0;
	for (int i = 0; i < str.length(); ++i) {
		L = L * Quaternion(str[i]);
		if (!prefixes.count(L))
			prefixes[L] = i + 1;
	}

	Quaternion S = '1';
	suffixes[S] = str.length();
	for (int i = str.length() - 1; i >= 0; --i) {
		S = Quaternion(str[i]) * S;
		if (!suffixes.count(S))
			suffixes[S] = i;
	}

	vector<Quaternion> LL = { '1', L, L * L, L * L * L };

	for (int i1 = 0; i1 < 4; i1++)
		for (int i2 = 0; i2 < 4; i2++)
			for (int i3 = 0; i3 < 4; i3++) {

				int rest = x - 2 - i1 - i2 - i3;
				if (rest < 0 || rest % 4)
					continue;

				Quaternion a1 = I / LL[i1];

				if (!prefixes.count(a1))
					continue;

				Quaternion b1 = L / a1;

				Quaternion a2 = J / (b1 * LL[i2]);

				if (!prefixes.count(a2))
					continue;

				Quaternion b2 = L / a2;

				if (b2 * LL[i3] == K)
					return true;
			}

	for (int i1 = 0; i1 < 4; i1++)
		for (int i2 = 0; i2 < 4; i2++) {
			
			int rest = x - 1 - i1 - i2;
			if (rest < 0 || rest % 4)
				continue;

			Quaternion a = I / LL[i1];
			if (!prefixes.count(a))
				continue;

			Quaternion b = (L / a) / J;

			if (!suffixes.count(b))
				continue;

			if (prefixes[a] >= suffixes[b])
				continue;
			
			if (b * LL[i2] == K)
				return true;
		}

	return false;
}

int main(int argc, char** argv)
{

	ifstream input("./C-small-attempt2.in");
	ofstream output("./out.txt");

	int T;
	input >> T;

	for (int i = 1; i <= T; ++i) {
		long long l, x;
		string str;
		input >> l >> x >> str;

		output << "Case #" << i << ": ";
		output << (solve(str, x) ? "YES" : "NO") << endl;
	}

	return 0;
}
