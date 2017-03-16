#include <iostream>
#include <string>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/A-small-attempt0.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output1.txt");

	ifile >> T;
	int ans = 0;

	for (size_t i = 0; i < T; i++)
	{
		int	 r, c, w;

		ifile >> r >> c >> w;

		if (w == c)
			ans = r - 1 + w;
		else
			if (c % w > 0)
				ans = r * (c / w) + w;
			else
				ans = r * (c / w) + w - 1;

		ofile << "Case #" << i + 1 << ": "<< ans << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}
