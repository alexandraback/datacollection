#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <cmath>
#include <iomanip>
#include "stdio.h"

using namespace std;
//typedef  __float128 ld;
typedef  long double ld;


int main(int argc, const char *argv[])
{
	int tc = 0;
	ifstream is;
	if (argc == 1)
		is.open("c:\\shiv\\gcj\\input.txt");
	else
		is.open(argv[1]);
	ofstream os;
	os.open("c:\\shiv\\gcj\\output.txt");

	string s;
	getline(is, s);
	istringstream iss(s);
	iss >> tc;

	for (int i = 1; i <= tc; i++)
	{
		os << "Case #" << i << ": ";
		unsigned int A, B, K;
		getline(is, s);
		istringstream iss(s);
		iss >> A >> B >> K;

		int result = 0;
		for (unsigned int i = 0; i < A; ++i) {
			for (unsigned int j = 0; j < B; ++j) {
				if ((i&j) < K) {
					++result;
				}
			}
		}

		ostringstream oss;
		oss << result;

		os << oss.str() << endl;
	}

	is.close();
	os.close();
	getchar();
	return 0;
}