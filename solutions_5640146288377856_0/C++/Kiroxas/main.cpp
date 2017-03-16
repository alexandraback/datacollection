#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
	ifstream file("A-small-attempt0.in");
	ofstream ofile("res.out");
	int tests;
	file >> tests;

	for(int i =0; i < tests; ++i)
	{
		int rows, column, width;

		file >> rows;
		file >> column;
		file >> width;

		float f = ceil((float)column / (float)width);
		float w = f * rows;

		float res = w + width - 1;


		ofile << "Case #" << i + 1 << ": " << res << endl;
	}


	return 0;
}
