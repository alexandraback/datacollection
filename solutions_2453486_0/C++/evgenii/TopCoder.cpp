// TopCoder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include <fstream>

int _tmain(int argc, _TCHAR* argv[])
{
	int testIntArray[] = {1, 2, 3, 4, 5, 6, 7};

	char* testCharArray[] = {"1111", "222", "3333", "444", "55555"};

	vector<int> testInt;
	for (int nIdx = 0; nIdx < sizeof(testIntArray) / sizeof(int); ++nIdx)
		testInt.push_back(testIntArray[nIdx]);

	vector<string> testChar;
	for (int nIdx = 0; nIdx < sizeof(testCharArray) / sizeof(char*); ++nIdx)
		testChar.push_back(testCharArray[nIdx]);


	std::ifstream ifs("test.txt");
	std::ofstream ofs("ans.txt");
	int n = 0;
	ifs >> n;
	for (int idx = 0; idx < n; ++idx) {
		vector<string> mx;
		char buff[5];
		memset(buff, 0, sizeof(buff));
		for (int idx2 = 0; idx2 < 4; ++idx2) {
			ifs >> buff;
			mx.push_back(buff);
		}

		bool xWin = false;
		bool yWin = false;
		bool undone = false;

		for (int i = 0; i < 4; ++i) {
			bool xrow = true;
			bool yrow = true;
			for (int j = 0; j < 4; ++j) {
				if (mx[i][j] != 'X' && mx[i][j] != 'T')
					xrow = false;
				if (mx[i][j] != 'O' && mx[i][j] != 'T')
					yrow = false;
				if (mx[i][j] == '.')
					undone = true;
			}
			if (xrow) {
				xWin = true;
				break;
			}
			if (yrow) {
				yWin = true;
				break;
			}
		}

		for (int i = 0; i < 4; ++i) {
			if (xWin || yWin)
				break;
			bool xrow = true;
			bool yrow = true;
			for (int j = 0; j < 4; ++j) {
				if (mx[j][i] != 'X' && mx[j][i] != 'T')
					xrow = false;
				if (mx[j][i] != 'O' && mx[j][i] != 'T')
					yrow = false;
			}
			if (xrow) {
				xWin = true;
				break;
			}
			if (yrow) {
				yWin = true;
				break;
			}
		}


		if (!xWin && !yWin) {
			bool xrow = true;
			bool yrow = true;
			for (int i = 0; i < 4; ++i) {
				if (xWin || yWin)
				break;
				if (mx[i][i] != 'X' && mx[i][i] != 'T')
					xrow = false;
				if (mx[i][i] != 'O' && mx[i][i] != 'T')
					yrow = false;
			}
			if (xrow)
				xWin = true;
			if (yrow)
				yWin = true;
		}

		if (!xWin && !yWin) {
			bool xrow = true;
			bool yrow = true;
			for (int i = 0; i < 4; ++i) {
				if (xWin || yWin)
				break;
				if (mx[i][3-i] != 'X' && mx[i][3-i] != 'T')
					xrow = false;
				if (mx[i][3-i] != 'O' && mx[i][3-i] != 'T')
					yrow = false;
			}
			if (xrow)
				xWin = true;
			if (yrow)
				yWin = true;
		}

		if (xWin)
			ofs << "Case #" << idx + 1 << ": X won" << std::endl;
		else if (yWin)
			ofs << "Case #" << idx + 1 << ": O won" << std::endl;
		else if (undone)
			ofs << "Case #" << idx + 1 << ": Game has not completed" << std::endl;
		else
			ofs << "Case #" << idx + 1 << ": Draw" << std::endl;
	}

	std::cout << "Done!!!" << std::endl;
	char buffer[120];
	std::cin >> buffer;
	return 0;
}

