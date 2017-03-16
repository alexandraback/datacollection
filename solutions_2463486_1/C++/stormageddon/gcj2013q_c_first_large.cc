#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
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

void PopulateFairSquares(vector<long long>* fairSquareList) {
	long long A = 1;
	long long B = pow(10.0, 14); // "magic number" 10^14
	long long startValue = floor(sqrt(static_cast<long double>(A)));
	while ((startValue * startValue) < A)
		startValue++;
	long long endValue = floor(sqrt(static_cast<long double>(B)));
	while ((endValue * endValue) <= B)
		endValue++;
	while (startValue < endValue) {
		if (!CheckFairness(startValue)) {
			startValue++;
			continue;
		}
		long long squareValue = startValue * startValue;
		if (CheckFairness(squareValue))
			fairSquareList->push_back(squareValue);
		startValue++;
	}
	return;
}

int main() {
	// Populate a list of fair and squares between 1 and 10^14.
	vector<long long> fairSquareList;
	PopulateFairSquares(&fairSquareList);

	int cases = 0;
	cin >> cases;
	for (int testCase = 1; testCase <= cases; testCase++) {
		cout << "Case #" << testCase << ": ";
		long long A = 0;
		cin >> A;
		long long B = 0;
		cin >> B;
		int fairAndSquares = 0;
		vector<long long>::iterator it = fairSquareList.begin();
		while (it != fairSquareList.end() && *it <= B) {
			if (*it >= A)
				fairAndSquares++;
			it++;
		}
		cout << fairAndSquares << endl;
	}
	return 0;
}
