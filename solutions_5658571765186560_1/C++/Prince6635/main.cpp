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
		int X, R, C;
		infile >> X >> R >> C;

		bool res = true;

		if (X >= 7)
			res = false;
		else if (X > R && X > C)
			res = false;
		else if (R * C % X != 0)
			res = false;
		else if ((X + 1) / 2 > min(R, C))
			res = false;
		else if (X == 1 || X == 2 || X == 3)
			res = true;
		else if (X == 4)
			res = min(R, C) > 2;
		else if (X == 5)
			res = !(min(R, C) == 3 && max(R, C) == 5);
		else if (X == 6)
			res = min(R, C) > 3;

		printf("Case #%d: %s\n", k + 1, res ? "GABRIEL" : "RICHARD");
	}

	return 0;
}