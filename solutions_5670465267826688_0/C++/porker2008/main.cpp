#include <iostream>
#include <string>
using namespace std;

int table[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1},
};

class quaternion {
public:
	int temp;
	int sign;
	quaternion operator*(const quaternion& another) const {
		quaternion result;
		result.temp = table[temp][another.temp];
		result.sign = sign * another.sign;
		if (result.temp < 0) {
			result.sign *= -1;
			result.temp *= -1;
		}
		return result;
	}
	quaternion() {
		temp = sign = 1;
	}
};

quaternion fastpow(quaternion a, long long b) {
	quaternion result;
	while (b) {
		if (b & 1) {
			result = result * a;
		}
		b >>= 1;
		a = a * a;
	}
	return result;
}

quaternion convert_from_char(char c) {
	quaternion result;
	if (c == '1') {
		result.temp = 1;
	} else {
		result.temp = c - 'i' + 2;
	}
	return result;
}

int main() {
	cin.sync_with_stdio(false);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		long long L, X;
		cin >> L >> X;
		string s;
		cin >> s;
		cout << "Case #" << cas << ": ";
		quaternion result;
		for (int i = 0; i < L; i++) {
			result = result * convert_from_char(s[i]);
		}
		quaternion overall = fastpow(result, X);
		//cout << overall.temp << " " << overall.sign << endl;
		if(overall.temp != 1 || overall.sign != -1) {
			cout << "NO" << endl;
			continue;
		}
		quaternion newresult;
		long long firstindex = -1;
		for (int i = 0; i < L * 4; i++) {
			newresult = newresult * convert_from_char(s[i%L]);
			if (newresult.temp == 2 && newresult.sign == 1) {
				firstindex = i;
				break;
			}
		}
		newresult = quaternion();
		long long secondindex = -1;
		for (int i = L * 4 - 1; i >= 0; i--) {
			newresult = convert_from_char(s[i%L]) * newresult;
			if (newresult.temp == 4 && newresult.sign == 1) {
				secondindex = i;
				break;
			}
		}
		//cout << firstindex << " " << secondindex << endl;
		if (firstindex == -1 || secondindex == -1) {
			cout << "NO" << endl;
			continue;
		}
		secondindex = X * L - (4 * L - secondindex);
		//cout << firstindex << " " << secondindex << endl;
		if (firstindex < secondindex) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}