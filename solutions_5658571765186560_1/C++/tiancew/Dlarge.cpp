#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	ofstream outfile("D:\\codejam\\2015\\Dlarge.txt");
	ifstream infile("D:\\codejam\\2015\\testcase.txt");

	int T;

	infile >> T;

	for (int casenum = 1; casenum <= T; casenum++)
	{
		int X, R, C;
		string ans;

		infile >> X >> R >> C;
		// make sure that R <= C
		if (R > C)
			swap(R, C);
		cout << "R=" << R << "C=" << C << endl;

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
		else if (X == 4)
		{
			if (R <= 2) ans = "RICHARD";
			else
			{
				if (R * C % 4 == 0) ans = "GABRIEL";
				else ans = "RICHARD";
			}
		}
		else if (X == 5)
		{
			if (R <= 2) ans = "RICHARD";
			else if (R == 3)
			{
				if (C > 5 && (C % 5 == 0)) ans = "GABRIEL";
				else ans = "RICHARD";
			}
			else // R >= 4
			{
				if (R * C % 5 == 0) ans = "GABRIEL";
				else ans = "RICHARD";
			}
		}
		else if (X == 6)
		{
			if (R >= 4 && C >= 6 && (R*C % 6 == 0))
				ans = "GABRIEL";
			else
				ans = "RICHARD";

		}
		else  // X >= 7, richard wins
		{
			ans = "RICHARD";
		}


		outfile << "Case #" << casenum << ": " << ans << endl;
	}

	cin.get();
	return 0;
}