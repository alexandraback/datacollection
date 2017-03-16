#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

bool carrylessSquare(const std::vector<int> &digits) {
	for (size_t i=0; i<digits.size(); i++) {
		int sum = 0;
		for (int j=0; j<=i; j++)
			sum += digits[j] * digits[i-j];
		if (sum>=10)
			return false;
	}
	return true;
}

/*std::vector<int> square(const std::vector<int> &digits) {
	std::vector<int> res(2*digits.size()-1);
	for (size_t i=0; i<digits.size(); i++) {
		int sum = 0;
		for (int j=0; j<=i; j++)
			sum += digits[j] * digits[i-j];
		res[res.size()-i-1] = res[i] = sum;
	}
	return res;
}*/

bool less(const std::vector<int> &a, const std::vector<int> &b) {
	if (a.size()!=b.size())
		return a.size()<b.size();
	return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

bool inRange(const std::vector<int> &x, const std::vector<int> &min, const std::vector<int> &max) {
	return (!less(x, min)) && (!less(max, x));
}

struct Square {
	std::vector<int> x, xx;
	Square(size_t digits): x(digits, 0), xx(2*digits-1, 0) { }
	bool incDigit(size_t index) {
		bool ok = true;
		for (size_t i=0; i<x.size(); i++) {
			xx[index+i] += 2*x[i];
			ok &= xx[index+i] < 10;
		}
		xx[2*index]++;
		x[index]++;
		ok &= xx[2*index] < 10;
		return ok;
	}
	void resetDigit(size_t index) {
		int digit = x[index];
		for (size_t i=0; i<x.size(); i++) {
			xx[index+i] -= 2*digit*x[i];
		}
		xx[2*index] += digit*digit;
		x[index] = 0;
	}
};

unsigned long long enumerate(Square &square, size_t knownDigits, const std::vector<int> &min, const std::vector<int> &max) {
	if (2*knownDigits>=square.x.size()) {
		return inRange(square.xx, min, max) ? 1 : 0;
	}
	size_t i1 = knownDigits;
	size_t i2 = square.x.size() - i1 - 1;
	unsigned long long res = 0;
	for (int newDigit=0; ; newDigit++) {
		res += enumerate(square, knownDigits+1, min, max);
		bool ok = square.incDigit(i1);
		if (i1!=i2)
			ok &= square.incDigit(i2);
		if (!ok) {
			square.resetDigit(i1);
			square.resetDigit(i2);
			return res;
		}
	}
}

std::vector<int> strToDigits(const std::string &s) {
	std::vector<int> res(s.size());
	std::transform(s.begin(), s.end(), res.begin(), [](char c)->int{return c-'0';});
	return res;
}

unsigned long long count(const std::vector<int> &min, const std::vector<int> &max) {
	unsigned long long res = 0;
	size_t minDigits = (min.size()+1) / 2;
	size_t maxDigits = (max.size()+1) / 2;
	for (size_t digits=minDigits; digits<=maxDigits; digits++) {
		Square square(digits);
		square.incDigit(0);
		if (square.x.size()!=1)
			square.incDigit(square.x.size()-1);
		res += enumerate(square, 0, min, max);
	}
	return res;
}

int main() {
	try {
		int T;
		std::string line;
		std::cin.exceptions(std::ios::failbit|std::ios::badbit);
		{
			std::getline(std::cin, line);
			std::istringstream fT(line);
			fT.exceptions(std::ios::failbit|std::ios::badbit);
			fT >> T;
		}
		for (int testIndex=1; testIndex<=T; testIndex++) {
			std::string min, max;
			{
				std::getline(std::cin, line);
				std::istringstream f(line);
				f.exceptions(std::ios::failbit|std::ios::badbit);
				f >> min >> max;
			}
			std::cout << "Case #" << testIndex << ": " << count(strToDigits(min), strToDigits(max)) << std::endl;
		}
	} catch (const std::exception &ex) {
		std::cerr << "exception: " << ex.what() << std::endl;
	}
	return 0;
}
