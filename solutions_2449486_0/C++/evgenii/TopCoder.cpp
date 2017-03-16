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
	int t = 0;
	ifs >> t;
	for (int idx = 0; idx < t; ++idx) {
		int n, m;
		ifs >> n;
		ifs >> m;
		vector<vector<int> > mx(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				char buff[10];
				memset(buff, 0, sizeof(buff));
				ifs >> buff;
				mx[i][j] = atoi(buff);
			}

		while(true) {
			int i1, j1, v1 = -1;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (mx[i][j] != -1 && (mx[i][j] < v1 || v1 == -1)) {
						v1 = mx[i][j];
						i1 = i;
						j1 = j;
					}

			if (v1 == -1) {
				ofs << "Case #" << idx + 1 << ": YES" << std::endl;
				break;
			}

			bool bGood = false;
			bool bValid = true;
			for (int i = 0; i < n; ++i) {
				if (mx[i][j1] == v1 || mx[i][j1] == -1)
					continue;
				bValid = false;
				break;
			}
			if (bValid) {
				bGood = true;
				for (int i = 0; i < n; ++i)
					mx[i][j1] = -1;
			}

			bValid = true;
			for (int j = 0; j < m; ++j) {
				if (mx[i1][j] == v1 || mx[i1][j] == -1)
					continue;
				bValid = false;
				break;
			}
			if (bValid) {
				bGood = true;
				for (int j = 0; j < m; ++j)
					mx[i1][j] = -1;
			}

			if (!bGood) {
				ofs << "Case #" << idx + 1 << ": NO" << std::endl;
				break;
			}
		}
	}

	std::cout << "Done!!!" << std::endl;
	char buffer[120];
	std::cin >> buffer;
	return 0;
}

