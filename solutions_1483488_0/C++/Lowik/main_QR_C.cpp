#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

//static ofstream dbgFile;

int GetNDigits(const int A) {
	if(A == 0) {return 1;}

	int n = 0;
	int b = 1;

	while(A >= b) {
		b *= 10;
		n++;
	}

	return n;
}

int GetStartBase(const int n_digits) {
	int start_base = 1;
	for(int i = 0; i < n_digits-1; i++) {
		start_base *= 10;
	}
	return start_base;
}

int GetNRecycledPairFrom(const int n, const int n_digits, const int start_base, const int max, const int qmax) {
	int n_pairs = 0;

	/* decompose n */
	vector<int> ni;
	int nc = n;

	for(int b = start_base; b != 0; b/=10) {
		int qi = nc/b;
		nc = nc - qi * b;
		ni.push_back(qi);
	}

	/* Do all transformation and check if the result is n < x <= max */
	/* i = number of digits moved */
	vector<int> results;

	for(size_t i = 1; i < n_digits; i++) {
		/* fast check : ni[n_digits - i] has to be != 0 and <= qmax and >= ni[0] */
		if(ni[n_digits - i] != 0 && ni[n_digits - i] <= qmax && ni[n_digits - i] >= ni[0]) {

			int result = 0;
			int base_10 = 1;
			for(int d = n_digits-1; d >= 0; d--) {
				result += ni[(n_digits - i + d)%n_digits] * base_10;
				base_10 *= 10;
			}
		
			if(result > n && result <= max) {
				if(results.end() == find(results.begin(), results.end(), result)) {
					//dbgFile << "{" << n << ", " << result << "}" << endl;
					results.push_back(result);
					n_pairs++;
				}
			}
		}
	}

	return n_pairs;
}

int GetNumbersOfRecycledPairs(const int A, const int B) {
	int total = 0;
	int n_digits = GetNDigits(A);
	int start_base = GetStartBase(n_digits);
	int qmax = B/start_base;

	for(int n = A; n <= B; n++) {
		total += GetNRecycledPairFrom(n, n_digits, start_base, B, qmax);
	}

	return total;

}


int main(int argc, char* argv[]) {
	string inTestName, outTestName;

	cout << "Enter the in test file name : " << endl;
	cin >> inTestName;
	cout << endl;

	cout << "Enter the out test file name : " << endl;
	cin >> outTestName;
	cout << endl;

	/* Open file */
	ifstream inFile(inTestName.c_str());
	if(!inFile.is_open()) {
		cout << "Can't open input file" << endl;
		system("PAUSE");
		return 1;
	}

	ofstream outFile(outTestName.c_str());
	if(!outFile.is_open()) {
		cout << "Can't open output file" << endl;
		system("PAUSE");
		return 1;
	}

	string dbg_name = outTestName + "_dbg.txt";
	//dbgFile.open(dbg_name.c_str());


	int T; /*number of tests */
	inFile >> T;

	for(int t = 0; t < T; t++) {
		int A, B;
		inFile >> A >> B;
		/*dbgFile << "Test # " << t + 1 << endl;
		dbgFile << "----------------------------------------" << endl;
		dbgFile << "A = " << A << " and B = " << B << endl << endl;*/
		int total = GetNumbersOfRecycledPairs(A, B);

		/* Write result */
		outFile << "Case #" << t+1 << ": " << total << endl;
	}

	outFile.close();
	inFile.close();
	//dbgFile.close();

	system("PAUSE");
	return 0;
}