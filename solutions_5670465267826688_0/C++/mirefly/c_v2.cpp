#include <iostream>
#include <string>
#include <vector>

using namespace std;

char prod(char a, char b, int & sign) {
	if (a == '1') {
		if (b == '1') {
			return '1';
		} else if (b == 'i') {
			return 'i';
		} else if (b == 'j') {
			return 'j';
		} else if (b == 'k') {
			return 'k';
		}
	} else if (a == 'i') {
		if (b == '1') {
			return 'i';
		} else if (b == 'i') {
			sign = -sign;
			return '1';
		} else if (b == 'j') {
			return 'k';
		} else if (b == 'k') {
			sign = -sign;
			return 'j';
		}
	} else if (a == 'j') {
		if (b == '1') {
			return 'j';
		} else if (b == 'i') {
			sign = -sign;
			return 'k';
		} else if (b == 'j') {
			sign = -sign;
			return '1';
		} else if (b == 'k') {
			return 'i';
		}
	} else if (a == 'k') {
		if (b == '1') {
			return 'k';
		} else if (b == 'i') {
			return 'j';
		} else if (b == 'j') {
			sign = -sign;
			return 'i';
		} else if (b == 'k') {
			sign = -sign;
			return '1';
		}
	}
	return 1;
}

int perm(char & a) {
	if (a == 'i') {
		a = 'j';
	} else if (a == 'j') {
		a = 'k';
	} else if (a == 'k') {
		a = 'i';
	}
}

int solve(int slen, int rn, string si) {
	long sl = slen * rn;
	char val = '1';
	int sign = 1;
	int left = sl;
	int right = -1;
	string s;
	for (int i = 0; i < rn; i++) {
		s += si;
	}
	//cout << s << endl;
	for (int i = 0; i < sl; i++) {
		val = prod(val, s[i], sign);	
	//	cout << i << " " << val << endl;
		if (val == 'i' && sign == 1) {
			left = i;
			break;
		}
	} 
	//cout << "----" << endl;
	val = '1';
	sign = 1;
	for (int i = sl - 1; i >= 0; i--) {
		val = prod(s[i], val, sign);
	//	cout << i << " " << val << endl;
		if (val == 'k' && sign == 1) {
			right = i;
			break;
		}
	}
	//cout << "lr" << left << " " << right << endl;
	if (left + 1 >= right) {
		return 0;
	}
	val = '1';
	sign = 1;
	for (int i = left + 1; i < right; i++) {
		val = prod(val, s[i], sign);
	//	cout << "mid "  << i << " " << sign << " " << val << endl;
	}
	if (val == 'j' && sign == 1) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int nt;
	cin >> nt;
	int sl;
	long long rn;
	string s;
	for (int i = 0; i < nt; i++) {
		cin >> sl;
		cin >> rn;
//		rn = rn % 12;
		cin >> s;
		cout <<  "Case #" << i + 1 << ": ";
		if (solve(sl, rn, s)) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		cout << endl;
		//cout << "----------" << endl;
	}
	return 0;
}
