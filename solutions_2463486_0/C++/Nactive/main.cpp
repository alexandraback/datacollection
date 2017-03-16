// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long uint;

bool IsPalindrome(uint number) {
	uint backup = number;
	uint omgedraaid = 0;

	//Reverse the number.
	while (number > 0) {
		omgedraaid = omgedraaid * 10 + number %10;
		number /= 10;
	}

	return omgedraaid == backup;
}

void buildAllNumbers(uint maximum, vector<uint> &out) {
	out.push_back(1);
	uint i = 2;
	uint root = i * i;
	while (root < maximum * maximum) {
		if (IsPalindrome(i) && IsPalindrome(root)) {
			out.push_back(root);
		}
		i++;
		root = i*i;
	}
}

int main() {
	ifstream in;
	in.open("C-small-attempt0.in");

	ofstream out;
	out.open("C-small-attempt0.out");

	vector<uint> square_dromes;
	buildAllNumbers(10000000, square_dromes);

	int aantal;
	in >> aantal;

	cout << "All information gathered, lets start solving!" << endl;

	for (int oef = 1; oef <= aantal; oef++) {
		uint onder; uint boven;
		in >> onder;
		in >> boven;

		int aantal = 0;

		for (int i = 0; i < square_dromes.size(); i++) {
			if (square_dromes[i] >= onder && square_dromes[i] <= boven)
				aantal++;
		}

		out << "Case #" << oef << ": " << aantal << endl;
	}

	in.close();
	out.close();


	return 0;
}