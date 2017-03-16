#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int T;
int X, R, C;

int get_result(int X, int R, int C)
{
	if (X >= 7)
		return 0;
	if ((R*C) % X != 0)
		return 0;
	if ((R == C && 2 * R <= X) || (2 * min(R, C) + 1 <= X))
		return 0;
	if (max(R, C) < X)
		return 0;
	if (X < 2 * min(R, C) - 1)
		return 1;
	if (min(R, C) == 2 && X == 4)
		return 0;
	if (min(R, C) == 3 && X == 6)
		return 0;
	if (min(R, C) == 3 && max(R, C) == 5 && X == 5)
		return 0;
	return 1;
}

int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("D-small-attempt0.in");
	ofile.open("output.txt");
	ifile >> T;
	int casenum = 0;
	while (casenum < T)
	{
		casenum++;
		ifile >> X >> R >> C;
		if (get_result(X, R, C))
			ofile << "Case #" << casenum << ": GABRIEL" << endl;
		else ofile << "Case #" << casenum << ": RICHARD" << endl;
	}

	return 0;
}