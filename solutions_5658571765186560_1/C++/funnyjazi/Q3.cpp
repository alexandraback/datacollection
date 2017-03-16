#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	int t = 0;
	string name[2] = { "GABRIEL", "RICHARD" };
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	if (fin.good())
	{
		fin >> t;

		for (size_t i = 0; i < t; i++)
		{
			int X, R, C;
			X = R = C = 0;
			fin >> X;
			fin >> R;
			fin >> C;
			bool p = true;

			if (X >= 7)
				p = false;
			else if (X>R && X > C)
				p = false;
			else if (R*C% X != 0)
				p = false;
			else if ((X + 1) / 2 > min(R,C))
				p = false;
			else if (X == 1 || X == 2 || X == 3)
				p = true;
			else if (X == 4)
				p = min(R, C) > 2;
			else if (X == 5)
				p = !(min(R, C) == 3 && max(R, C) == 5);
			else if (X == 6)
				p = min(R, C) > 3;

			
			if (p)
				fout << "Case #" << i + 1 << ": " << name[0] << endl;
			else
				fout << "Case #" << i + 1 << ": " << name[1] << endl;

		}
		fin.close();
		fout.close();
	}

	return 0;
}