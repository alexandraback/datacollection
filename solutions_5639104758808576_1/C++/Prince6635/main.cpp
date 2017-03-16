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
#include <cmath>
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
		string numStr, shyness;
		infile >> numStr >> shyness;

		int num = std::stoi(numStr);

		int sum = shyness[0] - '0', result = 0;
		for (int i = 1; i <= num; ++i)
		{
			int currNum = shyness[i] - '0';
			if (i <= sum)
			{
				sum += currNum;
			}
			else
			{
				result += i - sum;
				sum += currNum + i - sum;
			}
		}

		printf("Case #%d: %d\n", k + 1, result);
	}

	return 0;
}