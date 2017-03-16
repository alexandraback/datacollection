/**
 * Problem: Coin Jam
 * Author: Xi Chen (ceciexi@gmail.com)
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

#define SWAP(a,b) string c; c=a; a=b; b=c

int compare(string a, string b) {
	if (a.length()<b.length()) {
		return 0;
	}
	else if (a.length() == b.length()) {
		if (a<b) return 0;
	}return 1;
}

string subtract(string a, string b) {
	int flag = 0, i, j;
	if (!compare(a, b)) {
		flag = 1;
		SWAP(a, b);
	}
	int *su = new int[a.length()];
	memset(su, 0, sizeof(int)*a.length());
	for (i = 0; i<a.length() - b.length(); i++)
		su[i] = a[i] - '0';
	for (j = 0; i<a.length(); i++, j++)
		su[i] = a[i] - b[j];
	for (i = a.length() - 1; i>0; i--) {
		if (su[i]<0) {
			su[i - 1]--;
			su[i] += 10;
		}
	}
	char *c = new char[a.length() + 2];
	i = 0, j = 0;
	if (flag) c[j++] = '-';
	while (su[i] == 0) i++;
	while (i<a.length()) c[j++] = su[i++] + '0';
	c[j] = '\0';

	if (c[0] == '\0') { c[1] = '\0'; c[0] = '0'; }
	free(su);
	string s(c);
	return s;
}

string multiply(string num1, string num2) {
	string sum(num1.size() + num2.size(), '0');
	for (int i = num1.size() - 1; 0 <= i; --i) {
		int carry = 0;
		for (int j = num2.size() - 1; 0 <= j; --j) {
			int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
			sum[i + j + 1] = tmp % 10 + '0';
			carry = tmp / 10;
		}
		sum[i] += carry;
	}
	size_t startpos = sum.find_first_not_of("0");
	if (string::npos != startpos) {
		return sum.substr(startpos);
	}
	return "0";
}

string add(string num, string add) {
	int goBit = 0;
	if (num.length() < add.length()) {
		string tmp = num;
		num = add;
		add = tmp;
	}
	string tmp(num.length() - add.length(), '0');
	add = tmp + add;
	int len1 = num.length(), len2 = add.length();
	for (int i = len1 - 1; i >= 0; --i) {
		int tmp = ((num[i] - '0') + (add[i] - '0') + goBit);
		num[i] = tmp % 10 + '0';
		goBit = tmp / 10;
	}
	if (goBit != 0)
		num.insert(0, string(1, (char)goBit + '0'));
	return num;
}

string remain(string a, string b) {
	string ans = "0";
	while (compare(a, b)) {
		string tmpDivisor = b, multi = "1";
		string tmpDivisorx2 = multiply(tmpDivisor, "2");
		while (compare(a, tmpDivisorx2)) {
			tmpDivisor = tmpDivisorx2;
			tmpDivisorx2 = multiply(tmpDivisor, "2");
			multi = multiply(multi, "2");
		}
		a = subtract(a, tmpDivisor);
		ans = add(ans, multi);
	}
	return a;
}


string findDivider(string num) {
	int len = num.length();

	// check 2
	char last = num[len-1];
	if (last == '0' || last == '2' || last == '4' || last == '6' || last == '8')
		return "2";

	// check 3
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += (num[i] - '0');
	}
	if (sum % 3)
		return "3";

	// check 5
	if (last == '5')
		return "5";

	for (string i = "7"; compare("10", i); i = add(i, "1")) {
		if (remain(num, i) == "0")
			return i;
	}
	return "0";
}

string getNext(string str) {
	int i = str.length() - 1;
	while (--i) {
		if (str[i] == '1') {
			if (i == 1) return "#";
			str[i] = '0';
		}
		else {
			str[i] = '1';
			break;
		}
	}
	return str;
}

string convert(string str, string base) {
	string num = "0";
	for (int i = 0; i < str.length(); ++i) {
		num = multiply(num, base);
		if (str[i] == '1')
			num = add(num, "1");
	}
	return num;
}

string gen(int n) {
	string str = "1";
	for (int i = 2; i < n; i++) {
		str += "0";
	}
	str += "1";
	return str;
}

bool check(string input) {
	string result[9];
	int i = 0; string base = "2";
	for (; i < 9; ++i, base = add(base, "1")) {
		string num = convert(input, base);
		string d = findDivider(num);
		if (d=="0") return false;
		result[i] = d;
	}
	cout << input;
	for (int i = 0; i < 9; ++i)
		cout << ' ' << result[i];
	cout << endl;
	return true;
}

int main() {	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int N;
	cin >> N;
	for (int prob = 1; prob <= N; prob++) {
		cout << "Case #" << prob << ":" << endl;
		int n, j;
		cin >> n;
		cin >> j;
		string str = gen(n);
		while (j && str != "#") {
			if (check(str))
				--j;
			str = getNext(str);
		}
	}
	return 0;
}
