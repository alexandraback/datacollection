#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	ofstream outfile("D:\\codejam\\2015\\Dsmall.txt");
	ifstream infile("D:\\codejam\\2015\\testcase.txt");

	int T;

	infile >> T;

	for (int casenum = 1; casenum <= T; casenum++)
	{
		int X, R, C;
		string ans = "GABRIEL";
		
		infile >> X >> R >> C;
		// make sure that R <= C
		if (R > C)
			swap(R, C);

		if (X == 1) ans = "GABRIEL";
		else if (X == 2)
		{
			if ((R*C % 2)) ans = "RICHARD";  // odd number of squares
			else ans = "GABRIEL";
		}
		else if (X == 3)
		{
			if (R == 1) ans = "RICHARD";
			else
			{
				if (R * C % 3 == 0) ans = "GABRIEL";
				else ans = "RICHARD";
			}

		}
		else  // X == 4
		{
			if (R >= 3 && C == 4) ans = "GABRIEL";
			else ans = "RICHARD";
		}

		outfile << "Case #" << casenum << ": " << ans << endl;
	}
	infile.close();
	outfile.close();

	return 0;
}