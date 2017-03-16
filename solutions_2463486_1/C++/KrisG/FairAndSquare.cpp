//
//  FairAndSquare.cpp
//  Google Code Jam 2013
//
//  Created by Kristopher Giesing on 4/12/13.
//  Copyright (c) 2013 Kristopher Giesing. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include <cmath>

class Filter
{
public:
	Filter(uint64_t low, uint64_t high);
	
	bool test(uint64_t number);
	
private:
	uint64_t mLow;
	uint64_t mHigh;
};

Filter::Filter(uint64_t low, uint64_t high)
: mLow(low), mHigh(high)
{
}

bool
Filter::test(uint64_t number)
{
	//std::cout << "Testing palindrome: " << number << "\n";
	if (number < mLow || number > mHigh) {
		return false;
	}
	uint64_t square = number*number;
	std::ostringstream str;
	str << square;
	std::string sqstr = str.str();
	size_t len = sqstr.length();
	for (size_t i = 0; i < len/2; i++) {
		if (sqstr[i] != sqstr[(len-1)-i]) {
			return false;
		}
	}
	//std::cout << "Found palindrome whose square is too: " << number << " " << square << "\n";
	return true;
}

uint64_t palindromize(uint64_t number, int nDigits)
{
	//std::cout << "Palindromizing: " << number << " to " << nDigits << " digits\n";
	char result[nDigits+1];
	std::ostringstream str;
	str << number;
	std::string numberString = str.str();
	for (int i = 0; i < numberString.size(); i++) {
		result[i] = numberString[i];
		result[(nDigits-1)-i] = numberString[i];
	}
	result[nDigits] = 0;
	return strtoull(result, NULL, 10);
}

uint64_t
tenToPower(int power)
{
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *= 10;
	}
	return result;
}

int
countFilteredPalindromes(int nDigits, Filter filter)
{
	int result = 0;
	int minPow = (nDigits+1)/2 - 1;
	uint64_t min = tenToPower(minPow);     // e.g. 10^(5/2) = 10^(2) = 100
	uint64_t max = tenToPower(minPow+1)-1; // e.g. 10^(5/2+1)-1 = 10^(3)-1 = 999
	//std::cout << "counting palindromes " << nDigits << " wide: " << min << " to " << max << "\n";
	for (uint64_t i = min; i < max; i++) {
		if (filter.test(palindromize(i, nDigits))) {
			result++;
		}
	}
	return result;
}

int countDigits(uint64_t number)
{
	int result = 0;
	while (number > 0) {
		number /= 10;
		result++;
	}
	return result;
}

int
numberOfFairAndSquares(uint64_t low, uint64_t high)
{
	uint64_t lowBounds = std::ceil(std::sqrt(low));
	uint64_t highBounds = std::floor(std::sqrt(high));
	//std::cout << "low " << low << " became " << lowBounds << "\n";
	//std::cout << "high " << high << " became " << highBounds << "\n";
	Filter filter(lowBounds, highBounds);
	int lowDigits = countDigits(lowBounds);
	int highDigits = countDigits(highBounds);
	int result = 0;
	for (int i = lowDigits; i <= highDigits; i++) {
		//std::cout << "Counting palindromes with digits: " << i << "\n";
		result += countFilteredPalindromes(i, filter);
	}
	return result;
}

int main(int argc, const char * argv[])
{
	std::ifstream input(argv[1]);
	int nTests;
	input >> nTests;
	for (int i = 0; i < nTests; i++) {
		uint64_t low, high;
		input >> low;
		input >> high;
		std::cout << "Case #" << (i+1) << ": " << numberOfFairAndSquares(low, high) << "\n";
	}
	
    return 0;
}
