#define _CRT_SECURE_NO_DEPRECATE
#include <cstring>
#include <fstream>
#include <string.h>
#include <map>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

using namespace std;

int main(int argc, char *args[]) {
	std::ifstream infile("input.in");
	freopen("output.out", "w", stdout);

	int t;

	string line;
	std::getline(infile, line);
	t = std::stoi(line);

	for (int k = 0; k < t; ++k)
	{
		int num, curr;
		infile >> num;

		vector<int> pc;
		int maxNum = numeric_limits<int>::min();
		while (num > 0)
		{
			infile >> curr;
			maxNum = max(maxNum, curr);
			pc.emplace_back(curr);
			--num;
		}

		int times = 2, result = maxNum;
		while (times < maxNum)
		{
			int currRes = 0;
			for (int p : pc)
			{
				currRes += (p - 1) / times;
			}
			currRes += times;

			result = min(result, currRes);
			++times;
		}

		printf("Case #%d: %d\n", k + 1, result);
	}

	return 0;
}