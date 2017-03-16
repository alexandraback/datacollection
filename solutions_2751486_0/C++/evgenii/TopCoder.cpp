// TopCoder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include <fstream>

void genTests() {
	std::ofstream tests("test.txt");
	tests << "1000" << std::endl;
	for (int i = 0; i < 1000; ++i)
		tests << "1 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" << std::endl;
	tests.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	//genTests();
	std::ifstream ifs("test.txt");
	std::ofstream ofs("ans.txt");

	int t = 0;
	ifs >> t;
	char buff[1000001];
	long long int n = 0;
	for (int idx = 0; idx < t; ++idx) {
		ifs >> buff;
		ifs >> n;
		long long int len = strlen(buff);

		long long int res = 0;
		long long int li = 0;
		bool bFirst = true;
		for (long long int i = 0; i <= len - n; ++i) {
			bool bValid = true;
			for (int j = 0; j < n && bValid; ++j) {
				switch(buff[i + j]) {
					case 'a':
					case 'e':
					case 'i':
					case 'o':
					case 'u':
						bValid = false;
						break;
				}
			}
			if (!bValid)
				continue;

			long long int m1 = 0;
			if (bFirst) {
				m1 = i + 1;
				bFirst = false;
			} else
				m1 = i - li;
			res += m1*(len - i - n + 1LL);
			li = i;
		}
		ofs << "Case #" << idx + 1 << ": " << res << std::endl;
	}

	std::cout << "Done!!!" << std::endl;
	char buffer[120];
	std::cin >> buffer;
	return 0;
}

