#include <iostream>
#include <limits>
#include <sstream>
#include <cmath>
using namespace std;

bool CheckFairness(long long value) {
	stringstream stringizer;
	stringizer << value;
	string palindroMaybe = stringizer.str();
	int length = palindroMaybe.size();
	for (int offset = 0; offset < (length / 2); offset++)
		if (palindroMaybe.at(offset) != palindroMaybe.at((length - 1) - offset))
			return false;
	return true;
}

int main() {
	int cases = 0;
	cin >> cases;
	for (int testCase = 1; testCase <= cases; testCase++) {
		cout << "Case #" << testCase << ": ";
		long long A = 0;
		cin >> A;
		long long B = 0;
		cin >> B;
		long long startValue = floor(sqrt(static_cast<long double>(A)));
		while ((startValue * startValue) < A)
			startValue++;
		long long endValue = floor(sqrt(static_cast<long double>(B)));
		while ((endValue * endValue) <= B)
			endValue++;
		long long fairAndSquares = 0;
		while (startValue < endValue) {
			if (!CheckFairness(startValue)) {
				startValue++;
				continue;
			}
			if (CheckFairness(startValue * startValue))
				fairAndSquares++;
			startValue++;
		} // for testCase
		cout << fairAndSquares << endl;
	}
	return 0;
}
