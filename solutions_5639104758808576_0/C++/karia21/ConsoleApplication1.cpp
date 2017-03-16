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

	for (size_t i = 0; i < T; i++)
	{
		int ss;
		ifile >> ss;

		string cc;
		ifile >> cc;

		int cur_stand = int(cc.at(0) - '0');
		int ans = 0;
		for (size_t j = 1; j <= ss; j++)
		{
			if (int(cc.at(j) - '0') > 0 && cur_stand < j)
			{
				ans += j - cur_stand;
				cur_stand += j - cur_stand;
			}

			cur_stand += int(cc.at(j) - '0');
		}

		ofile << "Case #" << i+1 << ": " << ans << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}

