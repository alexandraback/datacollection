#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<unsigned> fairSquares;

bool IsPalindrome(int value) {
	vector<int> digits;
	int tmp(value);
	while(tmp > 0) {
		digits.push_back(tmp % 10);
		tmp /= 10;
	}
	int begin(0), end(digits.size() - 1);
	while(begin < end) {
		if(digits[begin] != digits[end])
			return false;
		begin++;
		end--;
	}
	return true;
} 

void Initialize() {
	unsigned i(1), square(1);
	do {
		square = (unsigned)pow(i, 2);
		if(IsPalindrome(i) && IsPalindrome(square))
			fairSquares.push_back(square);
		++i;
	}while(square <= 1000);
}

int main(int argc, char *argv[]) {

	fstream infile(argv[1]);
	if(!infile.is_open()) {
		cerr << "Could not open file " << argv[0] << endl;
		return -1;
	}

	Initialize();

	string line;
	getline(infile, line);
	int testCase = atoi(line.c_str());
	for(int i = 1; i <= testCase; ++i) {
		cout << "Case #" << i << ": ";
		getline(infile, line);
		stringstream ss(line);
		unsigned A(0), B(0);
		ss >> A >> B;
		int count(0);
		for(unsigned i = 0; i < fairSquares.size(); ++i) 
			if(fairSquares[i] >= A && fairSquares[i] <= B)
				count++;
		cout << count << endl;
	}

	return 0;
}