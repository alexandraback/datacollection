#include <iostream>
#include <vector>
using namespace std;

struct Quaternion {
	bool sign;
	int base;
	Quaternion(char base = 'h') : sign(false), base(base - 'i') {}
	Quaternion operator*(const Quaternion& other) const {
		Quaternion result;
		result.sign = sign != other.sign;
		if(other.base == -1) {
			result.base = base;
		} else if(base == -1) {
			result.base = other.base;
		} else if(base == other.base) {
			result.sign = !result.sign;
			result.base = -1;
		} else if((base + 1) % 3 == other.base) {
			result.base = (base + 2) % 3;
		} else {
			result.sign = !result.sign;
			result.base = (base + 1) % 3;
		}
		return result;
	}
	Quaternion operator/(const Quaternion& other) const {
		Quaternion result;
		result.sign = sign != other.sign;
		if(other.base == -1) {
			result.base = base;
		} else if(base == -1) {
			result.sign = !result.sign;
			result.base = other.base;
		} else if(base == other.base) {
			result.base = -1;
		} else if((base + 1) % 3 == other.base) {
			result.base = (base + 2) % 3;
		} else {
			result.sign = !result.sign;
			result.base = (base + 1) % 3;
		}
		return result;
	}
	bool operator==(const Quaternion& other) const {
		return sign == other.sign && base == other.base;
	}
};

Quaternion i = 'i';
Quaternion j = 'j';
Quaternion k = 'k';

int main() {
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int length, count;
		cin >> length >> count;
		if(count > 11) {
			count = 8 + count % 4;
		}
		vector<Quaternion> input(length);
		for(Quaternion& letter : input) {
			char base;
			cin >> base;
			letter = base;
		}
		vector<Quaternion> product(length * count + 1);
		for(int index = 0; index < length * count; ++index) {
			product[index + 1] = product[index] * input[index % length];
		}
		vector<int> split1, split2;
		for(int index = 1; index < length * 4 && index <= length * count - 2; ++index) {
			if(product[index] == i) {
				split1.push_back(index);
			}
		}
		for(int index = length * count - 1; index > length * (count - 4) && index >= 2; --index) {
			if(product[length * count] / product[index] == k) {
				split2.push_back(index);
			}
		}
		bool answer = false;
		for(int index1 : split1) {
			for(int index2 : split2) {
				if(index2 <= index1) {
					break;
				}
				if(product[index2] / product[index1] == j) {
					answer = true;
					break;
				}
			}
			if(answer) {
				break;
			}
		}
		cout << "Case #" << test << ": " << (answer ? "YES" : "NO") << '\n';
	}
	return 0;
}
