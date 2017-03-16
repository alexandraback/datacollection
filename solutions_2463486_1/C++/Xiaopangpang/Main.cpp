#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include "ttmath.h"

using namespace std;

typedef ttmath::UInt<2> UInt;

vector<UInt> fairSquares;

bool IsPalindrome(UInt value) {
	string strValue = value.ToString();
	int begin(0), end(strValue.size() - 1);
	while(begin < end) {
		if(strValue[begin] != strValue[end])
			return false;
		begin++;
		end--;
	}
	return true;
} 

void Initialize() {
	UInt i(1), square(1), max("10000000000000");
	do {
		square = i * i;
		if(IsPalindrome(i) && IsPalindrome(square))
			fairSquares.push_back(square);
		++i;
	}while(square <= max);
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
		UInt A, B;
		ss >> A >> B;
		UInt count(0);
		for(unsigned i = 0; i < fairSquares.size(); ++i) 
			if(fairSquares[i] >= A && fairSquares[i] <= B)
				count++;
		cout << count << endl;
	}

	return 0;
}