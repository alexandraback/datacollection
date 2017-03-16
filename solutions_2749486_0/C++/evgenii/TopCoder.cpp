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
	int x = 0;
	int y = 0;
	string res;
	for (int idx = 0; idx < t; ++idx) {
		ifs >> x;
		ifs >> y;
		int xpos = 0;
		int ypos = 0;
		res = "";
		while (xpos != x) {
			if (xpos > x) {
				res += "EW";
				--xpos;
			} else {
				res += "WE";
				++xpos;
			}
		}
		while (ypos != y) {
			if (ypos > y) {
				res += "NS";
				--ypos;
			} else {
				res += "SN";
				++ypos;
			}
		}
		ofs << "Case #" << idx + 1 << ": " << res.c_str() << std::endl;
	}

	std::cout << "Done!!!" << std::endl;
	char buffer[120];
	std::cin >> buffer;
	return 0;
}

