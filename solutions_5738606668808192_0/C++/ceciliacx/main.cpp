/**
 * Problem: Revenge of the Pancakes
 * Author: Xi Chen (ceciexi@gmail.com)
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <math.h>
#include <string>

long long findDivider(long long num) {
	for (long long i = 2; i <= (long long)sqrt(num); ++i) {
		if (!(num % i))
			return i;
	}
	return 0;
}

std::string getNext(std::string str) {
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

long long convert(std::string str, int base) {
	long long num = 0;
	for (int i = 0; i < str.length(); ++i) {
		num *= base;
		if (str[i] == '1')
			num += 1;
	}
	return num;
}

std::string gen(int n) {
	std::string str = "1";
	for (int i = 2; i < n; i++) {
		str += "0";
	}
	str += "1";
	return str;
}

bool check(std::string input) {
	long long result[9];
	for (int i = 2; i <= 10; ++i) {
		long long num = convert(input, i);
		long long d = findDivider(num);
		if (!d) return false;
		result[i - 2] = d;
	}
	std::cout << input;
	for (int i = 0; i < 9; ++i)
		std::cout << ' ' << result[i];
	std::cout << std::endl;
	return true;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	std::cin >> N;
	for (int prob = 1; prob <= N; prob++) {
		std::cout << "Case #" << prob << ":" << std::endl;
		int n, j;
		std::cin >> n;
		std::cin >> j;
		std::string str = gen(n);
		while (j && str != "#") {
			if (check(str))
				--j;
			str = getNext(str);
		}
	}
	return 0;
}