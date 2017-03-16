// TopCoder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include <fstream>

bool _isValid(long long int _val) {
	char buff[100];
	memset(buff, 0, sizeof(buff));
	long long int idx = 0;
	while(_val > 0) {
		buff[idx] = _val % 10;
		_val /= 10;
		++idx;
	}
	int mval = idx / 2;
	for (int i = 0; i < mval; ++i)
		if (buff[i] != buff[idx - i - 1])
			return false;
	return true;
}

void genTests() {
	std::ofstream tests("test.txt");
	tests << "10000" << std::endl;
	for (int i = 0; i < 10000; ++i)
		tests << "1 100000000000000" << std::endl;
	tests.close();
}

vector<long long int> fairs;
void solve() {
	long long int a = 1;
	long long int  b = 1LL << 14;
	long long int lval = sqrt((double)a);
	while(lval*lval < a)
		++lval;
	long long int uval = sqrt((double)b) + 1;
	while (uval*uval > b)
		--uval;

	//long long int lval2 = 1;
	//while (lval2*10 < sqrt((double)lval) + 1)
	//	lval2 *= 10;

	//long long int uval2 = 1;
	//while (uval2 < sqrt((double)uval) + 1)
	//	uval2 *= 10;

	for (long long int i = lval; i <= uval; ++i) {
		if (_isValid(i) && _isValid(i*i))
			fairs.push_back(i*i);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//genTests();
	solve();
	std::ifstream ifs("test.txt");
	std::ofstream ofs("ans.txt");
	int t = 0;
	ifs >> t;
	for (int idx = 0; idx < t; ++idx) {
		long long int a, b;
		ifs >> a;
		ifs >> b;
		long long int counter = 0;
		for (int i = 0; i < fairs.size(); ++i)
			if (a <= fairs[i] && fairs[i] <= b)
				++counter;
		ofs << "Case #" << idx + 1 << ": " << counter << std::endl;
	}

	std::cout << "Done!!!" << std::endl;
	char buffer[120];
	std::cin >> buffer;
	return 0;
}

