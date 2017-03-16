#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
//#include<vector>
//#include<set>
//#include<climit>
//#include<cmath>
//#include<cstdlib>  rand()

using namespace std;

int count(int C, int W)
{
	if (W == C) return W;
	else if (C >= W * 2 +1)
		return 1 + count(C - W, W);
	else
	{
		/*if ((C-W)%2 == 0)
			return  1 + count((C + W) / 2 - 1, W);
		else*/
			return W+1;
	}

}


int main()
{
	ofstream outfile("D:\\codejam\\2015\\R3\\output.txt");
	ifstream infile("D:\\codejam\\2015\\R3\\testcase.txt");

	int T;
	infile >> T;

	for (int casenum = 1; casenum <= T; casenum++)
	{
		int row, col, wid;
		infile >> row >> col >> wid;
		int y;
		if (row == 1)
			y = count(col, wid);
		else
		{
			y = (row-1) * (col / wid) + count(col, wid);
		}



		outfile << "Case #" << casenum << ": " << y << endl;
	}


	infile.close();
	outfile.close();
	return 0;
}
