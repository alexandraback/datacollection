#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <assert.h>
#include <functional>
using namespace std;

// X * 2 = R * C
bool haveSolution(int X, int R, int C)
{
	if (R + C - 1 <= X)
		return true;

	if (C == 2 && R >= 4)
		return true;

	if (C >= 4 && R == 2)
		return true;

	return false;
}

int main()
{
	ifstream file;
	ofstream output;
	file.open("data.in");
	output.open("data.out");
	int T;
	file >> T;
	for (int i = 1; i <= T; ++i)
	{
		int X, R, C;
		file >> X >> R >> C;

		int flag = false;
		if (R * C % X != 0)					// not divide
			flag = true;
		else if (R == 1 || C == 1)
		{
			if (X >= 3)
				flag = true;
			else
				flag = false;
		}
		else if (R == 2 || C == 2)
		{
			if (X >= 4)
				flag = true;
			else
				flag = false;
		}
		else if (R >= 3 && C >= 3)
		{
			if (X <= 5)
				flag = false;
			if (R + C <= X + 1)
				flag = true;
			int less = R < C ? R : C;
			if (X >= less * 2 + 1)
				flag = true;
			if (X >= 7)
				flag = true;
		}
		string outputStr = flag ? "RICHARD" : "GABRIEL";
		output << "Case #" << i << ": " << outputStr;
		if (i != T)
			output << endl;
	}
	file.close();
	output.close();
	return 0;
}